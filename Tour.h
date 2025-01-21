#ifndef TOUR_H
#define TOUR_H

#include "dimension.h"
#include <iostream>
using namespace std;

class Tour
{
	public:
		Tour(float r = 1, int x = 0, int y = 0);
		virtual ~Tour();
//		vitual void attaquer() = 0;
		void setPosition(int x, int y);
		Dimension getPosition();
		float getRange();
		void setRange(float r);
		void afficher(ostream &s);
		
	private:
		float range;
		Dimension dim;
		int prix;
};




#endif


