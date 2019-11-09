#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <ctime>
#include "get_machine_data.h"
#include "http.hpp"

HTTP servidor;
servidor.getData("18.191.146.49","80", "/desafio3/info/dados");
