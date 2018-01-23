/*
* File:   main.cpp
* Author: Axel Lammertz
*
* Created on 18. Januar 2018, 08:50
*/

//#include "DVK.h"
#include "DVKE.h"
#include "GEOKO.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
#include "stdafx.h"
#include "DVK.h"
using namespace std;

int main() {
	int anzahl;
	do {
		do {
			cout << "Bitte geben Sie die Anzahl Elemente ein.\n";
			cin >> anzahl;
		} while (anzahl < 0 || anzahl>1000000);
		DVK* liste = new DVK(anzahl);
		liste->InsertionSort();
	} while (1);
}