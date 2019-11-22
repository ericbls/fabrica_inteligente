#include "get_machine_data.h"

// Construtor de classe
getMachineData::getMachineData()
{
  HTTP servidor;
  unsigned short handle;
  short ret;
  char *pack_in[1000];
  char pack[1000];
  char ip_maq[20];
  int id_maq;
  char date_time[50];
  bool on_off;
}

void getMachineData::get_machines()
{
  servidor.getData("18.191.146.49", "80", "/desafio3/info/cadastro", pack_in);
  //json j_ip = json::parse(pack_in);
  //cout<<j_p[0]<<endl;
  //cout<<j_p[0]["ip"]<<endl;
  //cout<<j_ip.size()<<endl;
}

// Extração dos dados
void getMachineData::data_extract()
{
  // Conectando com a maquina
  ret = cnc_startupprocess(0,"test.log");
  ret = cnc_allclibhndl3(ip_maq, 8193, 10, &handle);

  cout<<"STATUS DE CONEXAO: "<<ret<<endl;
  if(ret!=0)
  {
      on_off = false;
  }else
  {
    on_off = true;
    // Extraindo dados de mensagem do PMC
    OPMSG3 opmsg;
    short int read_num=5;
    cnc_rdopmsg3(handle,0,&read_num,&opmsg);

    // Extraindo dados de status da maquina
    ODBST buf;
    cnc_statinfo(handle, &buf);

    // Criando pacote de envio
    sprintf(pack, "{\"maquina_id\":\"%d\",\"ip\":\"%s\",\"pmc_alm\":\"%s\",\"alm_stat\":\"%d\",\"emg_stat\":\"%d\",\"run_stat\":\"%d\",\"motion_stat\":\"%d\",",id_maq,ip_maq,opmsg.data,buf.alarm,buf.emergency,buf.run,buf.motion);
  }
}

// Função que envia os dados para o servidor desejado
void getMachineData::send_package()
{
  if(on_off)
  {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900+ltm->tm_year;
    int month = 1+ltm->tm_mon;
    int day = ltm->tm_mday;
    int hour = ltm->tm_hour;
    int minut = ltm->tm_min;
    int sec = ltm->tm_sec;
    sprintf(date_time, "\"time\":\"%d:%d:%d\",\"date\":\"%d/%d/%d\"}", hour,minut,sec,day,month,year);
    strcat(pack,date_time);
    cout<<"HORA E DATA DE EXTRACAO: "<<date_time<<endl;
    servidor.sendData("18.191.146.49", "80", "/desafio3/info/dados", "application/json", pack);
    cout<<"DADOS ENVIADOS:\n"<<pack<<endl;
  }else
  {
    cout<<"MÁQUINA INALCANÇÁVEL"<<endl;
  }
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
  for(int i=0; i<j_ip.size(); i++)
  {
    id_maq=j_ip[i]["id"];
    strcpy(ip_maq,string(j_ip[i]["ip"]).c_str());
    cout<<"\nPEGUEI O "<<i+1<<"# IP: "<<ip_maq<<endl;
    data_extract();
    send_package();
  }
  disconnect();
  cout<<"====================FINALIZANDO ITERACAO===================\n\n"<<endl;
}
