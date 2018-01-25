/*
* File:   GEOKO.cpp
* Author: Axel Lammertz
*
* Created on 15. Januar 2018, 11:03
*/


#include "DVKE.h"
#include "stdafx.h"
#include "GEOKO.h"
GEOKO::GEOKO() {
	BrGr = 0;
	BrMin = 0;
	BrSec = 0.0;
	LaGr = 0;
	LaMin = 0;
	LaSec = 0.0;
	DVKE();

}

void GEOKO::setBrGr(int a){
	BrGr = a;
}

void GEOKO::setBrMin(int a){
	BrMin = a;
}

void GEOKO::setBrSec(double a){
	BrSec = a;
}

void GEOKO::setLaGr(int a){
	LaGr = a;
}

void GEOKO::setLaMin(int a){
	LaMin = a;
}

void GEOKO::setLaSec(double a){
	LaSec = a;
}

void GEOKO::setabstand(double a){
	abstand = a;
}

bool GEOKO::operator<(GEOKO & in) {
	if (abstand < in.getabstand()) {
		return true;
	}
	return false;
}


int GEOKO::getBrGr(){
	return BrGr;
}

int GEOKO::getBrMin(){
	return BrMin;
}

double GEOKO::getBrSec(){
	return BrSec;
}

int GEOKO::getLaGr(){
	return LaGr;
}

int GEOKO::getLaMin(){
	return LaMin;
}

double GEOKO::getLaSec(){
	return LaSec;
}

double GEOKO::getabstand(){
	return abstand;
}



