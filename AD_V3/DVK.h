/*
* File:   DVK.h
* Author: Axel Lammertz
*
* Created on 16. Januar 2018, 16:07
*/

#ifndef DVK_H
#define DVK_H
#include "GEOKO.h"




class DVK {
public:
	DVK(int Anzahl);

private:
	GEOKO* Anker_V;
	GEOKO* Anker_R;
	GEOKO* Middle;
	GEOKO[] index;
	int Anz;

};

#endif /* DVK_H */

