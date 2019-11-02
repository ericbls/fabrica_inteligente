#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "http.hpp"
#include "fwlib32.h"

using namespace std;

class getMachineData
{

  // Construtor de classe
  getMachineData::getMachineData()
  {
    unsigned short handle;
    short ret;
    char pack[1000];
    char port[6] = "80";
    char target[20]="/desafio3/dados";
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
    sprintf(pack, "{\"pmc_msg\":\"%s\",\"alm_stat\":\"%d\",\"emg_stat\":\"%d\",\"run_status\":\"%d\",\"motion_stat\":\"%d\"}",opmsg.data,buf.alarm,buf.emergency,buf.run,buf.motion);
  }

  // Função que envia os dados para o servidor desejado
  void getMachineData::send_package()
  {
    HTTP servidor;
    servidor.sendData(ip_maq, port, target, "application/json", pack)
  }

  // Fechando conexao
  void getMachineData::machine_disconnect()
  {
    // Finalizando conexão
    cnc_exitprocess();
  }

}