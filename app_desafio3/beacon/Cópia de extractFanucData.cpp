/*
 * extractFanucData.cpp
 *
 *  Created on: 06 de maio de 2019
 *  Author Eric Lee
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <fstream>
#include "fwlib32.h"
#include "machineDict.h"

char *extractFanucData(char ip_maq[], char return_value[])
{
	ofstream file;
	unsigned short handle;
	short ret;
	ret = cnc_startupprocess(0, "./log/test.log");
	ret = cnc_allclibhndl3(ip_maq, 8193, 10, &handle);

	if(!ret)
	{
		//Retorna IP da máquina
		char ip[15];
		strcpy(ip,ip_maq);

		ODBSYS sysinfo;	// Chamando variável pointer, que armazena os dados do CNC
		cnc_sysinfo(handle,&sysinfo);

		//Retorna o num de série do CNC
		char series_no[10];
		char *p = sysinfo.series;
		p[5] = '\0';
		strcpy(series_no, p);

		//Retorna tipo de CNC da máquina
		char cnc_type[5];
		getCNCtype(sysinfo.cnc_type[0],sysinfo.cnc_type[1],cnc_type);

		if  (cnc_type != "Unrecognized")
		{
			//Index usado para contadores em for loops____________________
			unsigned short idx;

			//Retorna o tipo de máquina MT Type___________________________
			char mt_type[5];
			getMTtype(sysinfo.mt_type[1],sysinfo.mt_type[1],mt_type);

			//Inicializa extração de dado "statinfo"______________________
			char all_stats[6][30];
			getStats(handle, all_stats)
			//Retorna o status do modo automático da máquina
			char auto_stat[30];
			strcpy(auto_stat, all_stats[0]);
			//Retorna o status do modo "RUN" da máquina
			char run_stat[30];
			strcpy(alm_stat, all_stats[1]);
			//Retornao status do modo "ALARM" da máquina
			char alm_stat[30];
			strcpy(run_stat, all_stats[2]);
			//Retorna o status do modo "EDIT" da máquina
			char edit_stat[30];
			strcpy(edit_stat, all_stats[3]);
			//Retorna o status do modo "MOTION" da máquina
			char motion_stat[30];
			strcpy(run_stat, all_stats[4]);
			//Retornao status do modo "EMERGENCY" da máquina
			char emg_stat[30];
			strcpy(run_stat, all_stats[5]);

			//Retorna o tipo de ALARME do CNC_____________________________
			int *alm_type_num;
			alm_type_num=getALMnum(handle,3);
			char alm_type[3][100];	//cria uma lista com até 4 tipos de alarmes
			getALMtype(handle,3, alm_type);
			char alm_msg[3][100];	//cria uma lista com até 4 tipos de alarmes
			getALMmsg(handle,3, alm_msg);

			//Retorna a posição absoluta do eixo X,Y e Z__________________
			ODBAXIS absolute;
			long int absX;
			long int absY;
			long int absZ;
			cnc_absolute2(handle,1,8,&absolute);
			absX = absolute.data[0];
			cnc_absolute2(handle,2,8,&absolute);
			absY = absolute.data[0];
			cnc_absolute2(handle,3,8,&absolute);
			absZ = absolute.data[0];

			//Retorna o nome do programa em execução______________________
			char prgname[100];
			getPRGname(handle, prgname);


			//Retorna o "FEED RATE" da ferramenta_________________________
			long fdr;
			char fdr_unit[10];
			long spdl;
			char spdl_unit[10];
			ODBSPEED speed;
			cnc_rdspeed(handle,0, &speed);
			fdr = speed.actf.data;
			strcpy(fdr_unit, speed_unit[speed.actf.unit]);
			spdl = speed.acts.data;
			strcpy(spdl_unit, speed_unit[speed.acts.unit]);

			//Retorna o "Rate", porcentagem da velocidade total_____________
			int rate;
			rate=getRate(handle);

			//Ciclo para extrair os parâmetros de PMC_______________________
			IODBPSD param;
			short axno;
			axno = atoi(sysinfo.axes);
			cnc_rdparam(handle, 6750, -1, 4+1*MAX_AXIS, &param);
			long timer_on = param.u.ldata;
			cnc_rdparam(handle, 6752, -1, 4+1*MAX_AXIS, &param);
			long timer_op = param.u.ldata;
			cnc_rdparam(handle, 6754, -1, 4+1*MAX_AXIS, &param);
			long timer_cut = param.u.ldata;
			cnc_rdparam(handle, 6712, -1, 4+1*MAX_AXIS, &param);
			long counter = param.u.ldata;
			cnc_rdparam(handle, 6713, -1, 4+1*MAX_AXIS, &param);
			long counter_tgt = param.u.ldata;
			cnc_rdparam(handle, 6756, -1, 4+1*MAX_AXIS, &param);
			long timer_run = param.u.ldata;

			//Ciclo para extrair as mensagens de alarme do PMC______________
			char pmc_almtemp[100];
			char pmc_alm[4][100];
			for (idx=0; idx<4; idx++)
			{
				getPMCalm(handle,idx,pmc_almtemp);
				sprintf(pmc_alm[idx],"%s",pmc_almtemp);
			}



			// Montando JSON com todas as variáveis outputs
			snprintf(return_value,900,"{\"ip\": \"%s\",\"cnc_type\": \"%s\",\"mt_type\": \"%s\","
					"\"auto_stat\": \"%s\",\"run_stat\": \"%s\",\"motion_stat\": \"%s\","
					"\"edit_stat\": \"%s\",\"emg_stat\": \"%s\",\"alm_stat\": \"%s\","
					"\"alm_type1\": \"%s\",\"alm_type2\": \"%s\",\"alm_type3\": \"%s\","
					"\"absX\": \"%ld\",\"absY\": \"%ld\",\"absZ\": \"%ld\",\"prgname\": \"%s\","
					"\"fdr\": \"%ld\",\"fdr_unit\": \"%s\",\"spdl\": \"%ld\","
					"\"spdl_unit\": \"%s\",\"alm_list_msg1\": \"%s\",\"alm_list_msg2\": \"%s\","
					"\"alm_list_msg3\": \"%s\",\"series\": \"%s\","
					"\"counter\":\"%ld\",\"counter_tgt\":\"%ld\",\"timer_on\":\"%ld\","
					"\"timer_op\":\"%ld\",\"timer_cut\":\"%ld\",\"rate\":\"%d\",\"pmc_alm1\":\"%s\","
					"\"pmc_alm2\":\"%s\",\"pmc_alm3\":\"%s\",\"pmc_alm4\":\"%s\",\"timer_run\":\"%ld\"}",
					ip_maq, cnc_type, mt_type, auto_stat, run_stat,
					motion_stat, edit_stat, emg_stat, alm_stat,
					alm_type[0],alm_type[1],alm_type[2], absX,absY, absZ, prgname,
					fdr, fdr_unit, spdl, spdl_unit, alm_list_msg[0],alm_list_msg[1],
					alm_list_msg[2],series_no, counter,counter_tgt,timer_on,
					timer_op,timer_cut,rate,pmc_alm[0],pmc_alm[1],pmc_alm[2],pmc_alm[3],timer_run);

		}
		else
		{
			sprintf(return_value , "CNC model not supported"); // No caso de o CNC não for suportado
		}
	}

	else
	{
		sprintf(return_value , "CNC %s is unreachable: %d",ip_maq,ret);
	}

	file.open("./log/data.json");

	file << return_value << endl;

	file.close();

	return return_value; //JSON com todas as variáveis extraídas
}
