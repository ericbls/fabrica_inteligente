#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "http.hpp"
#include "fwlib32.h"

using namespace std;

int main()
{
    system("clear");
    // Inicializando comunicacao e funcoes______________________
    unsigned short handle;
    short ret;
  	char ip_maq[]="10.202.32.12";
  	char retvar[200];
    ret = cnc_startupprocess(0,"test.log");
    ret = cnc_allclibhndl3(ip_maq, 8193, 10, &handle);

    // Extraindo dados de mensagem do PMC________________________
    OPMSG3 opmsg;
  	char pmc_msg[200];
  	short int read_num=5;
  	cnc_rdopmsg3(handle,0,&read_num,&opmsg);
  	if (opmsg.datano==-1)
  	{
  		strcpy(pmc_msg,"NO ALARM\0");
  	}
  	else
  	{
  		strcpy(pmc_msg,opmsg.data);
  	}

    // Extraindo dados de status da maquina_______________________
    ODBST buf;
  	cnc_statinfo(handle, &buf);
    int alm_info = buf.alarm;
    int edit_info = buf.edit;
    int aut_info = buf.aut;
    int emg_info = buf.emergency;
    int run_info = buf.motion;
    int motion_info = buf.run;

    // Criando pacote de dados a ser enviado_____________________
    char package[500];
    sprintf(package, "PMC Message: %s\nAlarm status: %d\nEmg status: %d\nRun status: %d\nMotion status: %d\nThis is ERIC LEE\n",pmc_msg,alm_info,emg_info,run_info,motion_info);

    // Enviando os dados para rede_______________________________
    cout<<"\n====================== Server Output =========================\n";
    HTTP servidor;
    servidor.sendData("52.67.164.23","80", "/", "text/plain",package);

    // Finalizando conexão_______________________________________
    cnc_exitprocess();
    cout<<"\n====================== Machine Output ========================\n";
    cout<<"\n\nConection with machine status:\n"<<ret<<"\n";
    cout<<pmc_msg<<"\n";
    cout<<"\nGeneral machine status:\n";
    cout<<"alm_info: "<<alm_info<<"\n";
    cout<<"emg_info: "<<emg_info<<"\n";
    cout<<"run_info: "<<run_info<<"\n";
    cout<<"motion_info: "<<motion_info<<"\n";
    cout<<"edit_info: "<<edit_info<<"\n";
    cout<<"aut_info: "<<aut_info<<"\n";
    cout<<"\n\n"<<package;

  	return 0;
}
