/*
* File:   DVKE.h
* Author: Axel Lammertz
*
* Created on 13. Januar 2018, 23:56
*/

#ifndef DVKE_H
#define DVKE_H

class DVKE {
public:


	DVKE();
	void SetN(DVKE* N);
	DVKE* GetN();
	void SetV(DVKE* V);
	DVKE* GetV();

private:
	DVKE* V;
	DVKE* N;

};

#endif /* DVKE_H */

