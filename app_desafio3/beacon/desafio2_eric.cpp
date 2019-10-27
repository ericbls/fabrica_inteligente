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
    // Inicializando comunicacao e funcoes
    unsigned short handle;
    short ret;
  	char ip_maq[]="10.202.32.12";
  	char retvar[200];
    ret = cnc_startupprocess(0,"test.log");
    ret = cnc_allclibhndl3(ip_maq, 8193, 10, &handle);

    if (!ret)
    {
      // Extraindo dados de mensagem do PMC
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

      // Extraindo dados de status da maquina
      ODBST buf;
      cnc_statinfo(handle, &buf);

      // Criando pacote de dados a ser enviado
      char package[500];
      sprintf(package, '"pmc_msg":"%s","alm_stat":"%d","emg_stat":"%d","run_status":"%d","motion_stat":"%d"',pmc_msg,buf.alarm,buf.emergency,buf.run,buf.motion);

      // Enviando os dados para rede
      HTTP servidor;
      servidor.sendData("18.191.146.49","80", "/data", "application/json",package);

      // Finalizando conexão
      cnc_exitprocess();
     
      cout<<"\n"<<package<<"\n";
    }
    else
    {
      cout<<"machine is unreachable"
    }

  	return 0;
}
