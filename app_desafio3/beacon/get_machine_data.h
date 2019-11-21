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
  char pack_in[1000];
  char pack[1000];
  char ip_maq[20];
  int id_maq;
  char date_time[50];

  void get_machines();

  void execute();

private:

  HTTP servidor;
  short ret;

  void data_extract();

  void send_package();

  void disconnect();

};

#endif
