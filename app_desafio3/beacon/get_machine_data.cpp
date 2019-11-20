#include "get_machine_data.h"

// Construtor de classe
getMachineData::getMachineData()
{
  HTTP servidor;
  unsigned short handle;
  short ret;
  char *pack_in[1000];
  char pack[1000]
  char ip_maq[20];
  int id_maq;
}

void getMachineData::get_machines()
{
  servidor.getData("18.191.146.49", "80", "/desafio3/info/cadastro", pack_in);
  //json j_ip = json::parse(pack_in);
  //cout<<j_p[0]["ip"]<<endl;
  //cout<<j_ip.size()<<endl;
}

// Extração dos dados
void getMachineData::data_extract()
{
  // Conectando com a maquina
  ret = cnc_startupprocess(0,"test.log");
  ret = cnc_allclibhndl3(ip_maq, 8193, 10, &handle);

  // Extraindo dados de mensagem do PMC
  OPMSG3 opmsg;
  short int read_num=5;
  cnc_rdopmsg3(handle,0,&read_num,&opmsg);

  // Extraindo dados de status da maquina
  ODBST buf;
  cnc_statinfo(handle, &buf);

  // Criando pacote de envio
  sprintf(pack, "{\"maquina_id\":\"%d\"\"ip\":\"%s\",\"pmc_msg\":\"%s\",\"alm_stat\":\"%d\",\"emg_stat\":\"%d\",\"run_status\":\"%d\",\"motion_stat\":\"%d\",",id_maq,ip_maq,opmsg.data,buf.alarm,buf.emergency,buf.run,buf.motion);
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
void getMachineData::disconnect()
{
  // Finalizando conexão
  cnc_exitprocess();
}

// Executando em loops
void getMachineData::execute()
{
  json j_ip = json::parse(pack_in);
  for(int i; i<=j_ip.size(), i++)
  {
    id_maq=j_ip[i]["id"];
    strcpy(ip_maq,j_ip[i]["ip"]);
    data_extract();
    send_package();
  }
  disconnect();
}

