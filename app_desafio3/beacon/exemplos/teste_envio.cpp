#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "http.hpp"
#include "fwlib32.h"

using namespace std;

int main()
{
  // Criando pacote de dados a ser enviado
  char package[1000];

  //sprintf(package, "{'pmc_msg':'%s','alm_stat':'%d','emg_stat':'%d','run_status':'%d','motion_stat':'%d'}","MENSAGEM PMC",a,b,c,d);
  sprintf(package, "{\"pmc_msg\":\"%s\",\"alm_stat\":\"%d\",\"emg_stat\":\"%d\",\"run_status\":\"%d\",\"motion_stat\":\"%d\"}","MENSAGEM PMC",1,2,3,4);

  // Enviando os dados para rede
  HTTP servidor;
  servidor.sendData("18.191.146.49","80", "/desafio3/dados", "application/json",package);

  	return 0;
}
