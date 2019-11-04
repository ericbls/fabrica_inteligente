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

  void input_adress(const char* ip_maq);

  void machine_connect();

  void data_extract();

  void send_package();

  void machine_disconnect();
}
