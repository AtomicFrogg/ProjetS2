#ifndef TOUR_H
#define TOUR_H

#include "dimension.h"

using namespace std;

class Tour
{
	public:
		Tour(float r = 1, int x = 0, int y = 0);
		virtual ~Tour();
		virtual void attaquer() = 0;
		void setPosition(int x, int y);
		Dimension getPosition();
		float getRange();
		void setRange(float r);
		
		
	private:
		float range;
		Dimension dim;
};




#endif
