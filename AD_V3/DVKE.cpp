/*
* File:   DVKE.cpp
* Author: Axel Lammertz
*
* Created on 13. Januar 2018, 23:56
*/

//#include "DVKE.h"
#include "stdafx.h"
#include "DVKE.h"
DVKE::DVKE(){
	V = 0;
	N = 0;
}

void DVKE::SetN(DVKE * N){
	this->N = N;
}

DVKE * DVKE::GetN(){
	return N;
}

void DVKE::SetV(DVKE * V){
	this->V=V;
}

DVKE * DVKE::GetV(){
	return V;
}



