#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>


using namespace std;

class getMachineData
{
public:

  getMachineData();
  
  unsigned short handle;
  short ret;
  char pack[1000];
  char port[6];
  char target[20];

  void input_address(const char* ip_maq);

  void machine_connect();

  void data_extract();

  void send_package();

  void machine_disconnect();
};
