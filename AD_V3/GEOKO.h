/*
* File:   GEOKO.h
* Author: Axel Lammertz
*
* Created on 15. Januar 2018, 11:03
*/

#ifndef GEOKO_H
#define GEOKO_H
#include "DVKE.h"

class GEOKO : public DVKE {
public:
	GEOKO();
	void setBrGr(int a);
	void setBrMin(int a);
	void setBrSec(double a);
	void setLaGr(int a);
	void setLaMin(int a);
	void setLaSec(double a);
	void setabstand(double a);


	bool operator<(GEOKO& in);

	int getBrGr();
	int getBrMin();
	double getBrSec();
	int getLaGr();
	int getLaMin();
	double getLaSec();
	double getabstand();
	

private:
	int BrGr;
	int BrMin;
	double BrSec;
	int LaGr;
	int LaMin;
	double LaSec;
	double abstand;

};

#endif /* GEOKO_H */

