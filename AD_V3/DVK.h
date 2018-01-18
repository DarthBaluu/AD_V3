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
using namespace std;



class DVK {
public:
	DVK(int a);
	string keineLeerzeichen(string weg);

private:
	GEOKO* Anker_V;
	GEOKO* Anker_R;
	GEOKO* Middle;
	GEOKO* index[1000000];
	int Anz;

};

#endif /* DVK_H */

