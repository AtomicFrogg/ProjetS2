#ifndef TOURBASE1_H
#define TOURBASE1_H

#include "Tour.h"
#include "Defenseur.h"

class TourBase1: public Tour
{
	public:
		TourBase1(int d, float r, int x, int y, int va, int p, int t, Carte* c);
		~TourBase1();
		void attaquer();
		bool ameliorerRange();
		bool ameliorerDegat();
};




#endif
