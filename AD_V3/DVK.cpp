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
#include <time.h>
using namespace std;

DVK::DVK(int a) {
	Anz = a;
	int i;
	cout << "Fuer die Datei Daten.csv geben Sie bitte 1 ein.\nFuer die Datei Daten1.csv geben Sie bitte 2 ein.\n";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//string dateiname;
	if (choice == 1) {
		dateiname = "Daten.csv";
	}
	else if (choice == 2) {
		dateiname = "Daten1.csv";
	}
	else {
		cout << "Es ist ein Fehler aufgetreten.";
	}
	if ((choice == 1 || choice == 2) && Anz <= 1000000) {

		ifstream datareader;
		datareader.open(dateiname, ios::in);
		GEOKO* vorher = 0;
		int hilfe, zeilen = 0;
		double hilfe_2;

		for (i = 0; i < Anz; i++) {
			char brgr[255];
			char lgr[255];
			char splitten[255];

			string zeile, b, l;
			getline(datareader, zeile);
			int a = 0;
			splitten[a] = zeile[a];
			do {
				a++;
				splitten[a] = zeile[a];
			} while (zeile[a] != ';');
			split(brgr, lgr, splitten, a);

			b = brgr;
			l = lgr;
			double brges = atof(b.c_str());
			double lges = atof(l.c_str());
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
				temp->SetV(index[i - 1]);
				index[i - 1]->SetN(temp);

			}
			hilfe = (int)brges / 3600;
			temp->setBrGr(hilfe);
			hilfe = (brges - (hilfe * 3600)) / 60;
			temp->setBrMin(hilfe);
			hilfe_2 = brges - (temp->getBrGr() * 3600) - (temp->getBrMin() * 60);
			temp->setBrSec(hilfe_2);
			hilfe = (int)lges / 3600;
			temp->setLaGr(hilfe);
			hilfe = (lges - (hilfe * 3600)) / 60;
			temp->setLaMin(hilfe);
			hilfe_2 = lges - (temp->getLaGr() * 3600) - (temp->getLaMin() * 60);
			temp->setLaSec(hilfe_2);


			index[i] = temp;

			zeilen++;
		}

		datareader.close();

		GEOKO* temp = Anker_V;
		double allebreiten = 0, allelaengen = 0;
		int zaehler;


		for (zaehler = 0; zaehler < Anz; zaehler++) {
			allebreiten += (index[zaehler]->getBrGr() * 3600) + (index[zaehler]->getBrMin() * 60) + index[zaehler]->getBrSec();
			allelaengen += (index[zaehler]->getLaGr() * 3600) + (index[zaehler]->getLaMin() * 60) + index[zaehler]->getLaSec();

		}

		allebreiten = allebreiten / Anz;
		allelaengen = allelaengen / Anz;
		GEOKO* mitte = new GEOKO();

		hilfe = (int)allebreiten / 3600;
		mitte->setBrGr(hilfe);
		hilfe = (allebreiten - (hilfe * 3600)) / 60;
		mitte->setBrMin(hilfe);
		hilfe_2 = allebreiten - (mitte->getBrGr() * 3600) - (mitte->getBrMin() * 60);
		mitte->setBrSec(hilfe_2);
		hilfe = (int)allelaengen / 3600;
		mitte->setLaGr(hilfe);
		hilfe = (allelaengen - (hilfe * 3600)) / 60;
		mitte->setLaMin(hilfe);
		hilfe_2 = allelaengen - (mitte->getLaGr() * 3600) - (mitte->getLaMin() * 60);
		mitte->setLaSec(hilfe_2);
		Middle = mitte;
		cout << "Der Mittelpunkt befindet sich bei:\n";
		ausgabe(Middle);
		for (i = 0; i < Anz; i++) {
			GEOKO* li = index[i];
			double laenge = 0, breite = 0, laengemi = 0, breitemi = 0, abstand = 0;
			breite = (li->getBrGr() * 3600) + (li->getBrMin() * 60) + li->getBrSec();
			laenge = (li->getLaGr() * 3600) + (li->getLaMin() * 60) + li->getLaSec();

			breitemi += (Middle->getBrGr() * 3600) + (Middle->getBrMin() * 60) + Middle->getBrSec();
			laengemi += (Middle->getLaGr() * 3600) + (Middle->getLaMin() * 60) + Middle->getLaSec();

			abstand = sqrt(((breite - breitemi)*(breite - breitemi)) + ((laenge - laengemi)*(laenge - laengemi)));
			if (abstand < 0) {
				abstand = abstand * (-1);
			}
			index[i]->setabstand(abstand);

		}
	}

}

void DVK::split(char * br, char * la, char* eingabe, int laenge) {
	int i = 0, a = 0;
	while (eingabe[i] != ',') {
		br[i] = eingabe[i];
		i++;
	}
	if (eingabe[i] == ',' || eingabe[i] == ' ') {
		i++;
	}
	while (i <= laenge) {
		la[a] = eingabe[i];
		i++;
		a++;
	}
}

void DVK::InsertionSort() {
	int i, k, l;
	time_t beginn, aktuell;
	time(&beginn);
	GEOKO* temp, *temp_2;
	temp_2 = index[0];
	for (i = 1; i < Anz; i++) {
		temp = index[i];
		temp_2 = index[i - 1];
		if (i % 10000 == 0) {
			time(&aktuell);
			cout << i << "ter Durchgang.\nBenoetigte Zeit: " << aktuell - beginn << "\n\n\n";
			beginn = aktuell;
		}
		if (temp<temp_2) {
			for (k = 0; k < i; k++) {
				if (temp<temp_2) {
					if (k > 0 && k < Anz) {
						for (l = i; l >= k; l--) {
							index[l] = index[l - 1];
							if (l < Anz - 1) {
								index[l + 1]->SetV(index[l]);
								index[l]->SetN(index[l + 1]);
							}
						}
						index[k] = temp;
						index[k - 1]->SetN(index[k]);
						index[k]->SetV(index[k - 1]);
						index[k + 1]->SetV(index[k]);
						index[k]->SetN(index[k + 1]);
						break;
					}
					else if (k == 0) {
						for (l = i; l > k; l--) {
							index[l] = index[l - 1];
							index[l + 1]->SetV(index[l]);
							index[l]->SetN(index[l + 1]);
						}
						index[k] = temp;
						index[k]->SetV(0);
						index[k]->SetN(index[k + 1]);
						index[k + 1]->SetV(index[k]);
						Anker_V = index[k];
						break;
					}
					else if (k == Anz) {
						for (l = i; l > k; l--) {
							index[l] = index[l - 1];
							index[l + 1]->SetV(index[l]);
							index[l]->SetN(index[l + 1]);
						}
						index[k] = temp;
						index[k]->SetV(index[k - 1]);
						index[k - 1]->SetN(index[k]);
						index[k]->SetN(0);
						Anker_R = index[k];
						break;
					}
				}
			}
		}

	}


	ofstream fileout;
	string ausgabe;
	if (choice == 1) {
		ausgabe = "Daten_S.csv";
	}
	else if (choice == 2) {
		ausgabe = "Daten1_S.csv";
	}
	fileout.open(ausgabe);
	for (i = 0; i < Anz; i++) {
		string temp_1, temp_2;
		double breit, lang;
		breit = (index[i]->getBrGr() * 3600) + (index[i]->getBrMin() * 60) + index[i]->getBrSec();
		lang = (index[i]->getLaGr() * 3600) + (index[i]->getLaMin() * 60) + index[i]->getLaSec();
		temp_1 = to_string(breit);
		temp_2 = to_string(lang);
		fileout << temp_1 << "  ,  " << temp_2 << endl;
	}
	fileout.close();
}


void DVK::ausgabe(GEOKO* in) {
	string br1, br2, br3, la1, la2, la3;
	br1 = to_string(in->getBrGr());
	br2 = to_string(in->getBrMin());
	br3 = to_string(in->getBrSec());
	la1 = to_string(in->getLaGr());
	la2 = to_string(in->getLaMin());
	la3 = to_string(in->getLaSec());
	cout << "Breitengrad: " << br1 << "\nBreitenminuten: " << br2 << "\nBreitensekunden: " << br3 << "\nLaengengrad: " << la1 << "\nLaengenminuten: " << la2 << "\nLaengensekunden: " << la3 << "\n\n\n";
}