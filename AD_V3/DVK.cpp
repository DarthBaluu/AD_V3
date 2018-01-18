/*
* File:   DVK.cpp
* Author: Axel Lammertz
*
* Created on 16. Januar 2018, 16:07
*/

//#include "DVK.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
#include "stdafx.h"
#include "DVK.h"
using namespace std;

DVK::DVK(int a) {
	Anz = a;
	int i, choice;
	cout << "Fuer die Datei Daten.csv geben Sie bitte 1 ein.\nFuer die Datei Daten1.csv geben Sie bitte 2 ein.\n";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string dateiname;
	if (choice == 1) {
		dateiname = "Daten.csv";
	}
	else if (choice == 2) {
		dateiname = "Daten1-csv";
	}
	else {
		cout << "Es ist ein Fehler aufgetreten.";
	}
	if ((choice == 1 || choice == 2) && Anz <= 1000000) {
		ifstream datareader;
		datareader.open(dateiname, ios::in);
		GEOKO* vorher=0;
		int hilfe,zeile=0;
		for (i = 0; i < Anz; i++) {
			string brgr, lgr;
			//getline(datareader, brgr, ',');
			getline(datareader, lgr, '\n');
			brgr = keineLeerzeichen(brgr);
			lgr = keineLeerzeichen(lgr);
			double brges = atof(brgr.c_str());
			double lges = atof(lgr.c_str());
			GEOKO* temp = new GEOKO();
			if (i == 0) {
				Anker_V = temp;
				temp->SetV(0);
			}
			else if (i == (Anz - 1)) {
				Anker_R = temp;
				temp->SetN(0);
			}
			else {
				temp->SetV(vorher);
			}
			hilfe = (int) brges/3600;
			temp->setBrGr(hilfe);
			hilfe = (brges - (hilfe*3600)) / 60;
			temp->setBrMin(hilfe);
			hilfe = fmod(brges, 60.0);
			temp->setBrSec(hilfe);
			hilfe = (int)lges / 3600;
			temp->setLaGr(hilfe);
			hilfe = (lges - (hilfe * 3600)) / 60;
			temp->setBrMin(hilfe);
			hilfe = fmod(lges, 60.0);
			temp->setLaSec(hilfe);
			zeile++;
		}
		datareader.close();
	}
}

string DVK::keineLeerzeichen(string weg){
	string neu;
	int i = 0, a = 0;
	while (weg[i] != NULL) {
		if (weg[i] != ' ') {
			neu[a] = weg[i];
			a++;
		}
		i++;
	}
	return neu;
}
