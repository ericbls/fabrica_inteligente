#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "http.hpp"
#include "fwlib32.h"

using namespace std;

class getMachineData
{

  // Construtor de classe
  getMachineData::getMachineData()
  {
    unsigned short handle;
    HTTP servidor;
    short ret;
    char pack[1000];
    char port[6] = "80";
    char target[20]="/desafio3/info/dados";
  }

  void getMachineData::get_machines()
  {
    servidor.getData("18.191.146.49","80", "/desafio3/info/cadastro");
  }


  // Função que receberá como input os dados de entrada da máquina
  void getmachineData::input_address(const char* ip)
  {
    char ip_maq[20] = ip;
  }

  // Função para inicializar comunicação com a máquina
  void getMachineData::machine_connect()
  {
    ret = cnc_startupprocess(0,"test.log");
    ret = cnc_allclibhndl3(ip_maq, 8193, 10, &handle);
  }

  // Extração dos dados
  void getMachineData::data_extract()
  {
    // Extraindo dados de mensagem do PMC
    OPMSG3 opmsg;
    short int read_num=5;
    cnc_rdopmsg3(handle,0,&read_num,&opmsg);

    // Extraindo dados de status da maquina
    ODBST buf;
    cnc_statinfo(handle, &buf);

    // Criando pacote de envio
    sprintf(pack, "{\"pmc_msg\":\"%s\",\"alm_stat\":\"%d\",\"emg_stat\":\"%d\",\"run_status\":\"%d\",\"motion_stat\":\"%d\",",opmsg.data,buf.alarm,buf.emergency,buf.run,buf.motion);
  }

  // Função que envia os dados para o servidor desejado
  void getMachineData::send_package()
  {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900+ltm->tm_year;
    int month = 1+ltm->tm_mon;
    int day = ltm->tm_day;
    int hour = 1+ltm->tm_hour;
    int minut = 1+ltm->tm_min;
    int sec = 1+ltm->tm_sec;
    strcat(pack, "\"time\":\"%d:%d:%d\",\"date\":\"%d/%d/%d\"}",hour,minut,sec,day,month,year);
    servidor.sendData(ip_maq, port, target, "application/json", pack)
  }

  // Fechando conexao
  void getMachineData::machine_disconnect()
  {
    // Finalizando conexão
    cnc_exitprocess();
  }

};
