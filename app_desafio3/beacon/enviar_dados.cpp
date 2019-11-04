#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include "get_machine_data.h"

int main{

  HTTP servidor;
  getMachineData dados_maq;

  while(true)
  {
    servidor.getData("18.191.146.49","80", "/desafio3/dados");
    char maquinas[4][20]=servidor.res;
    char old_pack[4][1024];

    /* Precisa ver aqui como que eu pego o dado e coloco em uma matriz */

    for (i=1,i<=length(maquinas),i++)
    {
      dados_maq.input_address(maquinas[i]);
      dados_maq.machine_connect();
      dados_maq.data_extract();

      if (!dados_maq.ret)
      {
        if strcmp(old_pack[i],dados_maq.pack)!=0
        {

          dados_maq.send_package();
        }
        old_pack[i]=dados_maq.pack;
      }
      else
      {
        cout<<"machine "<<maquinas[i]<<" is unreachable\n";
      }
    }
  sleep(10);
  }
  return 0;
}
