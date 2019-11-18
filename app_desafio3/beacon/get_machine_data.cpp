#include "get_machine_data.h"

class getMachineData
{

  // Construtor de classe
  getMachineData::getMachineData()
  {
    unsigned short handle;
    HTTP servidor;
    short ret;
    char server_ip[20] = "18.191.146.49";
    char pack[1000];
    char port[6] = "80";
    char target[20]="/desafio3/info/cadastro";
    //char *all_ips;
    //int *all_ids;
    char ip_maq[20];
    int id_maq;
  }

  char getMachineData::get_machines_ips()
  {
    servidor.getData(server_ip, port, target, pack);
    json jip = pack_json;
    int total_machines = jip["ip"].size();
    //char all_ips[total_machines][20];
    for(int i = 0; i<=total_machines; i++)
    {
      strcpy(all_ips[i],jip.ip[i]);
    }
    return all_ips;
  }

  int getMachineData::get_machines_ids()
  {
    servidor.getData(server_ip, port, target, pack);
    json jid = pack_json;
    //int total_machines = j["id"].size();
    int all_ids[total_machines];
    for(int i = 0; i<=total_machines; i++)
    {
      all_ids[i]=j.maquina_id[i];
    }
    return all_ids;
  }

  // Função que receberá como input os dados de entrada da máquina
  void getmachineData::input_address(char ip, int id)
  {
    strcpy(ip_maq,ip);
    id_maq=id;
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
  void getMachineData::machine_disconnect()
  {
    // Finalizando conexão
    cnc_exitprocess();
  }

};
