#ifndef TOUR_H
#define TOUR_H

#include "dimension.h"
#include <iostream>
using namespace std;

class Tour: public Defenseur
{
	public:
		int getPrix();
		void setPrix(int p);
		int getTier();
		void setTier(int t);
		
	private:
		int prix;
		int tier;
};




#endif


