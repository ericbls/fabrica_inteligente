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
    dados_maq.execute();

    sleep(10);
  }
  return 0;
}
