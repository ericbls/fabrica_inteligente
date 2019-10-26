/*
 *	execute extraction.cpp
 *
 *  Created on: 07 de maio de 2019
 *  Author Eric Buonpater Lee Santos
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "fwlib32.h"
#include "extractFanucData.cpp"

using namespace std;

int main()
{
	char ip[]="10.202.32.12";
	char retvar[1200];
	extractFanucData(ip, retvar);
	cout<<retvar<<"\n";
	return 0;
}
