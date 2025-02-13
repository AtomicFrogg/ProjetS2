#ifndef TOURBASE1_H
#define TOURBASE1_H

#include "Tour.h"

class TourBase1: public Tour
{
	public:
		TourBase1(int d = 5, float r = 3, int x = 0, int y = 0, int p = 300, int t = 1, Carte* c)
		~TourBase1();
		void attaquer();
		bool ameliorerRange();
		bool ameliorerDegat();
};




#endif
