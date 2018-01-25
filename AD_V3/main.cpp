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

	int choice;
	int anzahl;
	DVK* liste = NULL;
	do {
		cout << "Bitte wählen Sie einen der Folgenden Punkte:\n'1' fuer das Anlegen einer Verketteten Liste.\n'2' fuer das Sortieren mit Insertion sort.\n'3' fuer das Sortieren mit Merge sort.\n'0' um das Programm zu beenden.\n\n";
		cin >> choice;
		switch (choice) {

		case 1: do {
			cout << "Bitte geben Sie die Anzahl Elemente ein.\n";
			cin >> anzahl;
			cout << "\n";
		} while (anzahl < 0 || anzahl>1000000);
		liste = new DVK(anzahl);
		break;


		case 2: liste->InsertionSort();
			break;
		case 3:
			break;

		case 0: cout << "Das Programm wurde beendet.";
			break;

		default:
			break;
		}

	} while (choice != 0);
}

