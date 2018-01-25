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
#include "math.h"
#include "windows.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int choice;
	int anzahl;
	DVK* liste = NULL;
	LONGLONG g_Frequency, g_FirstNullCount, g_LastNullCount, g_FirstCount, g_LastCount;
	double dTimeDiff, resolution, nulltime, time;
	do {
		cout << "Bitte wählen Sie einen der Folgenden Punkte:\n'1' fuer das Anlegen einer Verketteten Liste.\n'2' fuer das Sortieren mit Insertion sort.\n'3' fuer das Sortieren mit Merge sort.\n'0' um das Programm zu beenden.\n\n";
		cin >> choice;
		switch (choice) {

		case 1 : do {
			cout << "Bitte geben Sie die Anzahl Elemente ein.\n";
			cin >> anzahl;
			cout << "\n";
		} while (anzahl < 0 || anzahl>1000000);
		liste = new DVK(anzahl);
		break;


		case 2: //----------------------------------------------------------------------
	//
	//    Zeitmessung im æs-Bereich
	//    TESTANWENDUNG
	//    Author: tbird
	//    Date: 20.11.2007
	//
	//----------------------------------------------------------------------
	//Variablen
	

	//Frequenz holen
			if (!QueryPerformanceFrequency((LARGE_INTEGER*)&g_Frequency))
				printf("Performance Counter nicht vorhanden");

			resolution = 1000000 / ((double)g_Frequency);

			printf("Frequenz des Counters:  %lld kHz\n", g_Frequency / 1000);  //lld -> LONGLONG darstellung
			printf("Dadurch maximale Aufloesung: %4.5f us\n", resolution);

			//null-messung
			QueryPerformanceCounter((LARGE_INTEGER*)&g_FirstNullCount);
			QueryPerformanceCounter((LARGE_INTEGER*)&g_LastNullCount);
			nulltime = (((double)(g_LastNullCount - g_FirstNullCount)) / ((double)g_Frequency));

			printf("Null-Zeit: %4.5f us\n", nulltime * 1000000);

			//beginn messung
			QueryPerformanceCounter((LARGE_INTEGER*)&g_FirstCount);



			// Hier ist der Aufruf fuer Ihr Sortierverfahren, Beispiel: Heap
			liste->InsertionSort();
			

			//2. Messung
			QueryPerformanceCounter((LARGE_INTEGER*)&g_LastCount);

			dTimeDiff = (((double)(g_LastCount - g_FirstCount)) / ((double)g_Frequency));

			//Von der gemessenen Zeit die "Null-Zeit" abziehen, um genauer zu werden
			time = (dTimeDiff - nulltime) * 1000000; //mikro-sekunden
			printf("Zeit: %4.5f us\n", time);
			break;
	
		case 3:	//----------------------------------------------------------------------
				//
				//    Zeitmessung im æs-Bereich
				//    TESTANWENDUNG
				//    Author: tbird
				//    Date: 20.11.2007
				//
				//----------------------------------------------------------------------
				//Variablen
	

				//Frequenz holen
				if (!QueryPerformanceFrequency((LARGE_INTEGER*)&g_Frequency))
					printf("Performance Counter nicht vorhanden");

				resolution = 1000000 / ((double)g_Frequency);

				printf("Frequenz des Counters:  %lld kHz\n", g_Frequency / 1000);  //lld -> LONGLONG darstellung
				printf("Dadurch maximale Aufloesung: %4.5f us\n", resolution);

				//null-messung
				QueryPerformanceCounter((LARGE_INTEGER*)&g_FirstNullCount);
				QueryPerformanceCounter((LARGE_INTEGER*)&g_LastNullCount);
				nulltime = (((double)(g_LastNullCount - g_FirstNullCount)) / ((double)g_Frequency));

				printf("Null-Zeit: %4.5f us\n", nulltime * 1000000);

				//beginn messung
				QueryPerformanceCounter((LARGE_INTEGER*)&g_FirstCount);



				// Hier ist der Aufruf fuer Ihr Sortierverfahren, Beispiel: Heap
				liste->HeapSort();


				//2. Messung
				QueryPerformanceCounter((LARGE_INTEGER*)&g_LastCount);

				dTimeDiff = (((double)(g_LastCount - g_FirstCount)) / ((double)g_Frequency));

				//Von der gemessenen Zeit die "Null-Zeit" abziehen, um genauer zu werden
				time = (dTimeDiff - nulltime) * 1000000; //mikro-sekunden
				printf("Zeit: %4.5f us\n", time);
				break;
		case 0: cout << "Das Programm wurde beendet.";
			break;

		default:
			break;
		}

	} while (choice != 0);
	
}
