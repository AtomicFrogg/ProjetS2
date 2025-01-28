#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include "dimension.h"
#include <iostream>
using namespace std;

class Defenseur
{
	public:
		Defenseur(int d = 1, float r = 1, int x = 0, int y = 0);
		virtual ~Defenseur();
		virtual void attaquer() = 0;
		void setPosition(int x, int y);
		Dimension getPosition();
		float getRange();
		void setRange(float r);
		virtual void afficher(ostream &s);
		
	private:
		float range;
		Dimension dim;
		int degat;
};





#endif
