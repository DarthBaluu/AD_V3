/*
* File:   DVK.h
* Author: Axel Lammertz
*
* Created on 16. Januar 2018, 16:07
*/

#ifndef DVK_H
#define DVK_H
#include "GEOKO.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <math.h>
using namespace std;



class DVK {
public:
	DVK(int a);
	string keineLeerzeichen(string weg);
	void split(char* br, char* la, char* eingabe, int laenge);
	void InsertionSort();
	bool kleinerals(GEOKO* li,GEOKO* re);
	void ausgabe(int a);

private:
	GEOKO* Anker_V;
	GEOKO* Anker_R;
	GEOKO* Middle;
	GEOKO* index[1000000];
	string dateiname;
	int choice;
	int Anz;

};

#endif /* DVK_H */

