#ifndef getMachineData_h
#define getMachineData_h

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "http.hpp"
#include "fwlib32.h"
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class getMachineData
{
public:

  getMachineData();

  unsigned short handle;
  HTTP servidor;
  short ret;
  char pack_in[1000];
  char ip_maq[20];
  int id_maq;

  void get_machine_ips();

  void input_address(const char* ip_maq);

  void machine_connect();

  void data_extract();

  void send_package();

  void machine_disconnect();
};

#endif
