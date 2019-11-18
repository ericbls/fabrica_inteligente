#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <ctime>
#include "get_machine_data.h"

int main(){

  getMachineData dados_maq;

  while(true)
  {
    dados_maq.get_machines();
    char old_pack[4][1024];
    
    /* Precisa ver aqui como que eu pego o dado e coloco em uma matriz */

    for (int i=1;i<=sizeof(maquinas);i++)
    {
      dados_maq.input_address(maquinas[i]);
      dados_maq.machine_connect();
      dados_maq.data_extract();

      if (!dados_maq.ret)
      {
        if (strcmp(old_pack[i],dados_maq.pack)!=0)
        {

          dados_maq.send_package();
        }
        strcpy(old_pack[i],dados_maq.pack);
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
