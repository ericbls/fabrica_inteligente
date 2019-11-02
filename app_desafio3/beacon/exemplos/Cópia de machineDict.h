/*
 * machineDict.h
 *
 *  Created on: 06 de maio de 2019
 *  Author Eric Buonpater Lee Santos
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fwlib32.h"
using namespace std;


// Conjunto de mensagens para cada modelo CNC

char aut_msg15[6][30] = {"Not auto mode", "MDI", "15.TAPE/15i.DNC",
						   "MEMory","EDIT","TeacH IN"};
char aut_msg16[11][30] = {"MDI", "MEMory", "****","EDIT","HaNDle","JOG",
						   "Teach in JOG","TeacH in HaNDle","INC feed",
						   "REFerence","ReMoTe"};


char run_msg15[14][30] = {"STOP", "HOLD", "STaRT","MSTR jog mdi",
						   "ReSTaRt not blinking","Program RSTR","Seq. num search",
						   "ReSTaRt blinking","ReSET","unnused","unnused","unnused",
						   "unnused","HPCC"};
char run_msg16[5][30] = {"****","STOP","HOLD","STaRT","MSTR"};


char edit_msg15[7][30] = {"Not editting","EDIT","SeaRCH","VeRiFY",
						  "CONDense","READ","PuNCH"};
char edit_msg16M[61][30] = {"Not editting","EDIT","SeaRCH","OUTPUT","INPUT","COMPARE",
							"Label SKip","ReSTaRt","HPCC","PTRR","RVRS","RTRY","RVED",
							"HANDLE","OFSeT","Work OFSeT","AICC/AI-APC","MEmory-CHecK",
							"CusToMers BoarD","SAVE","AI NANO","AI APC","MBL APC","AICC 2",
							"AI HPCC","5AXIS","LEN","RAD","WZR","Empty","Empty","Empty",
							"Empty","Empty","Empty","Empty","Empty","Empty","Empty",
							"TCP","TWP","TCP+TWP","APC","PRG-CHK","APC","S-TCP","AICC 2",
							"Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty",
							"Empty","Empty","Empty","Empty","ALL SAVE","NOTSAVE"};
char edit_msg16T[61][30] = {"Not editting","EDIT","SeaRCH","OUTPUT","INPUT","COMPARE",
							"Label SKip","OFSeT","Work ShiFT","ReSTaRt","RVRS","RTRY","RVED",
							"Empty","PTRR","Empty","AICC/AI-APC","MEmory-CHecK",
							"Empty","SAVE","AI NANO","HPCC","Empty","AICC 2",
							"AI HPCC","5AXIS","OFSX","OFSZ","WZR","OFSY","Empty","TOFS",
							"Empty","Empty","Empty","Empty","Empty","Empty","Empty",
							"TCP","TWP","TCP+TWP","APC","PRG-CHK","APC","S-TCP","Empty",
							"Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty",
							"Empty","Empty","Empty","Empty","ALL SAVE","NOTSAVE"};


char motion_msg15[4][30] = {"****","MoTioN","DWeLI","Wait"};
char motion_msg16[3][30] = {"****","MoTioN","DWeLI"};

char emergency_msg15[2][30] = {"Not emergency","EMerGency"};
char emergency_msg16[4][30] = {"Not emergency","EMerGency","ReSET","WAIT"};

char alarm_msg15[2][30] = {"No alarm","ALarM"};
char alarm_msg16[9][30] = {"****","ALarM","BATtery low","FAN NC/Servo amp","PS warning",
							 "FSsB warning","INSulate warning","ENCoder warning","PMC alarm"};

char alm_type15[33][50] = {"BACKGROUND P/S","FOREGROUND P/S","Empty","Empty","SYNC ERROR",
							"PARAM. SWITHC ON","OVERTRAVEL/EXT DATA","PMC ERROR",
							"EXT ALM MSG 1","Empty","SERIOUS P/S","Empty","SERVO ALARM",
							"IO ERROR","POWER OFF PARAM SET","SYSTEM ALARM","EXT ALM MSG 2",
							"EXT ALM MSG 3","EXT ALM MSG 4","MACRO ALARM","SPINDLE ALARM",
							"Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty",
							"Empty","Empty","Empty","NO ALARM"};
char alm_type16[33][50] = {"P/S 100 ALARM","P/S 000 ALARM","P/S 101 ALARM","P/S ALARM (1-255)",
	                  		"OVERTRAVEL ALARM","OVERHEAT ALARM","SERVO ALARM","SYSTEM ALARM",
	                  		"APC ALARM","SPINDLE ALARM","P/S ALARM (5000-)","LASER ALARM",
	                  		"Empty","RIGID TAP ALARM","Empty","EXTERNAL ALARM MSG","Empty",
	                  		"Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty",
	                  		"Empty","Empty","Empty","Empty","Empty","Empty","Empty","NO ALARM"};
char alm_type30[33][50] = {"PARAMETER SWITCH ON","POWER OFF PARAMETER SET","I/O ERROR",
						 	"FOREGROUND P/S","OVERTRAVEL EXTERNAL DATA","OVERHEAT ALARM",
							"SERVO ALARM","DATA I/O ERROR","MACRO ALARM","SPINDLE ALARM",
							"OTHER ALARM DS","ALARM CONCERNING MALFUNCTION PREVENT FUNCS",
							"BACKGROUND P/S","SYNCRONIZED ERROR", "RESERVED","EXTERNAL ALARM MSG",
							"RESERVED","RESERVED","RESERVED","PMC ERROR","RESERVED","RESERVED",
							"RESERVED","RESERVED","RESERVED","RESERVED","RESERVED","RESERVED",
							"RESERVED","RESERVED","RESERVED","RESERVED","NO ALARM"};

char speed_unit[5][10] = {"mm/min","inch/min","rpm","mm/rev","inch/rev"};


//Função de extração de dados CNC Model_________________________________________________________________________
char *getCNCtype(char sysinfo0, char sysinfo1, char cnc_ret[])
{

	// Para cada retorno possível da função, foi criado um caso
	if (sysinfo0=='1' && sysinfo1=='5') 
	{
		strcpy(cnc_ret,"15");
	}
	else if (sysinfo0=='1' && sysinfo1=='6')
	{
		strcpy(cnc_ret,"16");
	}
	else if (sysinfo0=='1' && sysinfo1=='8')
	{
		strcpy(cnc_ret,"18");
	}
	else if (sysinfo0=='2' && sysinfo1=='1')
	{
		strcpy(cnc_ret,"21");
	}
	else if (sysinfo0=='3' && sysinfo1=='0')
	{
		strcpy(cnc_ret,"30");
	}
	else if (sysinfo0=='3' && sysinfo1=='1')
	{
		strcpy(cnc_ret,"31");
	}
	else if (sysinfo0=='3' && sysinfo1=='2')
	{
		strcpy(cnc_ret,"32");
	}
	else if (sysinfo0=='3' && sysinfo1=='5')
	{
		strcpy(cnc_ret,"35");
	}
	else if (sysinfo1=='0')
	{
		strcpy(cnc_ret,"0");
	}
	else if (sysinfo0=='P' && sysinfo1=='D')
	{
		strcpy(cnc_ret,"PD");
	}
	else if (sysinfo0=='P' && sysinfo1=='H')
	{
		strcpy(cnc_ret,"PH");
	}
	else if (sysinfo0=='P' && sysinfo1=='M')
	{
		strcpy(cnc_ret,"PM");
	}
	else
	{
		strcpy(cnc_ret,"Unrecognized");
	}
	
	return cnc_ret;
}

//Função de extração de dados MT Model__________________________________________________________________________
char *getMTtype(char sysinfo0, char sysinfo1, char mt_ret[])
{

	// Para cada retorno possível da função, foi criado um caso
	if (sysinfo0=='M' && sysinfo1=='M') 
	{
		strcpy(mt_ret,"MM");
	}
	else if (sysinfo0=='M' && sysinfo1=='T')
	{
		strcpy(mt_ret,"MT");
	}
	else if (sysinfo0=='M' && sysinfo1=='G')
	{
		strcpy(mt_ret,"MG");
	}
	else if (sysinfo0=='M')
	{
		strcpy(mt_ret,"M");
	}
	else if (sysinfo0=='T' && sysinfo1=='T')
	{
		strcpy(mt_ret,"TT");
	}
	else if (sysinfo0=='T')
	{
		strcpy(mt_ret,"T");
	}
	else if (sysinfo0=='P')
	{
		strcpy(mt_ret,"P");
	}
	else if (sysinfo0=='L')
	{
		strcpy(mt_ret,"L");
	}
	else if (sysinfo0=='W')
	{
		strcpy(mt_ret,"W");
	}
	else
	{
		strcpy(mt_ret,"Unrecognized");
	}
	
	return mt_ret;
}

//Função de extração dos números dos tipos de ALARME ativos______________________________________________________
int *getALMnum(unsigned short handle, unsigned short max_alm)
{
	long alm;
	cnc_alarm2(handle, &alm);
	unsigned short idx;
	unsigned short idx2=0;
	int *alm_list = new int[40];	// Existem apenas 32 tipos de alarmes,
								// Mas é bom deixar uma folga de memória.

	if (alm == 0)
	{
		alm_list[33]=0;
		//O último valor [33] é reservado para retornar o n° 
		// total de alarmes reconhecidos na máquina. Neste caso
		// é repassado 1 valor de alarme que será a mensagem
		// "No alarm".
	}
	else
	{

		for (idx = 0; idx <= 31 ; idx++)
		{
    		if (alm & 0x0001)
    		{
				alm_list[idx2]=idx;
				idx2++;
			}
			alm >>= 1 ;
    	}
    	alm_list[33]=idx2;
	}
	
	// Na hora de retornar o valor final em "extractFanucData"
	// há 3 variáveis reservadas para alarmes. O ciclo abaixo
	// garantirá que, caso haja menos do que 3 alarmes, os espaços
	// remanescentes sejam ocupados com a mensagem 32, que é "NO
	// ALARM".
	if (alm_list[33]<max_alm)
	{
		for (idx = alm_list[33];idx<max_alm;idx++)
		{
			alm_list[idx]=32;
		}
	}

	return alm_list;
}

//Função de extração dos tipos de ALARME ativos__________________________________________________________________
char *getALMtype(unsigned short handle, unsigned short max_alm, alm_type[])
{
	char alm_type[max_alm][100];
	if (strcmp(cnc_type,"15")==0)
	{
		for (idx=0; idx < max_alm; idx++)
		{
			strcpy(alm_type[idx], alm_type15[alm_list[idx]]);
		}
	} 
	else if (strcmp(cnc_type,"16")==0 || strcmp(cnc_type,"18")==0 || strcmp(cnc_type,"21")==0 || strcmp(cnc_type,"PM")==0)
	{
		for (idx=0; idx < max_alm; idx++)
		{
			strcpy(alm_type[idx], alm_type16[alm_list[idx]]);
		}
	}
	else
	{
		for (idx=0; idx < max_alm; idx++)
		{
			strcpy(alm_type[idx], alm_type30[alm_list[idx]]);
		}
	}
}

//Função de extração das mensagens de ALARMES ativos_____________________________________________________________
char *getALMmsg(unsigned short handle, unsigned short max_alm, alm_msg[])
{
	char alm_msg[max_alm][100];
	if (strcmp(cnc_type,"15")==0)
	{
		for (idx=0; idx < max_alm; idx++)
		{
			strcpy(alm_msg[idx], "Not Supported");
		}
	} 
	else if (strcmp(cnc_type,"16")==0 || strcmp(cnc_type,"18")==0 || strcmp(cnc_type,"21")==0 || strcmp(cnc_type,"PM")==0)
	{
		for (idx=0; idx < max_alm; idx++)
		{
			strcpy(alm_msg[idx] , "Not Supported");
		}
	}
	else
	{
		ODBALMMSG2 almmsg;
		for (idx=0; idx < max_alm; idx++)
		{
			cnc_rdalmmsg2(handle, alm_type_num[idx], &qt_alm, &almmsg);
			strcpy(alm_msg[idx] , almmsg.alm_msg);
		}
	}
	return alm_msg;
}

//Função de extração do valor de rate da máquina_________________________________________________________________
int getRate(unsigned short handle)
{
    IODBPMC *pmcrng;
    char rate_hex[20],rate[20];
    short ret,idx;
    short adr_type, data_type;
    unsigned short length, start, end;
    int percent;
    start = 10;
    end = 10;
    adr_type = 0;                       // In case that kind of PMC address is G
    data_type = 0;                      // In case that type of PMC data is Byte
    length = 8 + (end - start + 1);
    pmcrng = (IODBPMC *)malloc( length );
    ret = pmc_rdpmcrng( handle, adr_type, data_type, start, end, length, pmcrng );
    if ( !ret )
    {
		for ( idx = 0 ; idx <= end-start ; idx++ )
		{
			sprintf(rate_hex,"%02X",(unsigned char)pmcrng->u.cdata[idx]);
		}
    }
    else
    {
    	sprintf(rate_hex,"ERROR!(%d)\n",ret);
    }

    char *r=rate_hex;
    r[3]='\0';
    strcpy(rate,r);

    if (rate[0]=='D' && rate[1]=='F')
    {
    	percent=200;
    }
    else if (rate[0]=='C' && rate[1]=='7')
    {
    	percent=190;
    }
    else if (rate[0]=='A' && rate[1]=='F')
    {
    	percent=180;
    }
    else if (rate[0]=='9' && rate[1]=='7')
    {
    	percent=170;
    }
    else if (rate[0]=='7' && rate[1]=='F')
    {
    	percent=160;
    }
    else if (rate[0]=='6' && rate[1]=='7')
    {
    	percent=150;
    }
    else if (rate[0]=='4' && rate[1]=='F')
    {
    	percent=140;
    }
    else if (rate[0]=='3' && rate[1]=='7')
    {
    	percent=130;
    }
    else if (rate[0]=='1' && rate[1]=='F')
    {
    	percent=120;
    }
    else if (rate[0]=='0' && rate[1]=='7')
    {
    	percent=110;
    }
    else if (rate[0]=='E' && rate[1]=='F')
    {
    	percent=100;
    }
    else if (rate[0]=='D' && rate[1]=='7')
    {
    	percent=90;
    }
    else if (rate[0]=='B' && rate[1]=='F')
    {
    	percent=80;
    }
    else if (rate[0]=='A' && rate[1]=='7')
    {
    	percent=70;
    }
    else if (rate[0]=='8' && rate[1]=='F')
    {
    	percent=60;
    }
    else if (rate[0]=='7' && rate[1]=='7')
    {
    	percent=50;
    }
    else if (rate[0]=='5' && rate[1]=='F')
    {
    	percent=40;
    }
    else if (rate[0]=='4' && rate[1]=='7')
    {
    	percent=30;
    }
    else if (rate[0]=='2' && rate[1]=='F')
    {
    	percent=20;
    }
    else if (rate[0]=='1' && rate[1]=='7')
    {
    	percent=10;
    }
    else if (rate[0]=='F' && rate[1]=='F')
    {
    	percent=0;
    }
    else
    {
    	percent=-1;
    }

    return percent;
}
//Função de extração dos alarmes ativos de PMC____________________________________________________________________
char *getPMCalm(unsigned short handle, unsigned short idx, char pmc_alm[])
{
	OPMSG3 opmsg;
	char pmc_msg[100];
	short int read_num=5;
	cnc_rdopmsg3(handle,idx,&read_num,&opmsg);
	if (opmsg.datano==-1)
	{
		strcpy(pmc_msg,"NO ALARM\0");
	}
	else
	{
		strcpy(pmc_msg,opmsg.data);
	}
	sprintf(pmc_alm,"%d - %s",opmsg.datano,pmc_msg);
	return pmc_alm;
}

//Função de extração dos status da máquina________________________________________________________________________
char *getStats(unsigned short handle, char all_stats[])
{
	ODBST buf;
	cnc_statinfo(handle, &buf);

	if (strcmp(cnc_type,"15")==0)
	{
		strcpy(all_stats[0], aut_msg15[buf.aut]);			// Status do automático
		strcpy(all_stats[1], alarm_msg15[buf.alarm]);		// Status de alarme
		strcpy(all_stats[2], run_msg15[buf.run]);			// Status de execução de ciclo
		strcpy(all_stats[3], edit_msg15[buf.edit]);		// Status de edição na máquina
		strcpy(all_stats[4], motion_msg15[buf.motion]);	// Status de movimento
		strcpy(all_stats[5], emergency_msg15[buf.emergency]);//Status de emergência
	}
	else
	{
		strcpy(all_stats[0], aut_msg16[buf.aut]);	// Status do automático
		strcpy(all_stats[1],alarm_msg16[buf.alarm]);	// Status de alarme
		strcpy(all_stats[2], run_msg16[buf.run]);	// Status de execução de ciclo
		strcpy(all_stats[4], motion_msg16[buf.motion]);	//Status de movimento
		strcpy(all_stats[5], emergency_msg16[buf.emergency]);	//Status de emergência
		// Status de edição na máquina
		if (strcmp(mt_type,"T") || strcmp(mt_type,"MT") || strcmp(mt_type,"TT"))
		{
			strcpy(all_stats[3], edit_msg16T[buf.edit]);
		}
		else
		{
			strcpy(all_stats[3], edit_msg16M[buf.edit]);
		}
	}

	return all_stats;
}

//Função de extração do nome do programa em execução em usinagem da máquina_______________________________________
char *getPRGname(unsigned short handle, char prgname[])
{
	ODBEXEPRG exeprg;
	if (strcmp(cnc_type,"15")==0)	//Para modelos CNC 15 ou 15i
	{
		strcpy(prgname , "Not supported");
	}

	else //Para os outros modelos
	{
		// Para modelos CNC Fanuc 16, 18, 21 e PM e suas versões I
		if (strcmp(cnc_type,"16")==0 || strcmp(cnc_type,"18")==0 || strcmp(cnc_type,"21")==0 || strcmp(cnc_type,"PM")==0)
		{
			strcpy(prgname , "Not supported");

		// Para modelos CNC Fanuc 0 e 30, superiores e versões I
		else
		{
			cnc_exeprgname(handle,&exeprg);
			strcpy(prgname , exeprg.name);
		}
	}

	return prgname;
}