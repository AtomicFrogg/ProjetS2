#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include "dimension.h"
#include <iostream>
using namespace std;

class Defenseur
{
	public:
		Defenseur(float r = 1, int x = 0, int y = 0, int p = 100, int t = 0);
		virtual ~Defenseur();
		virtual void attaquer() = 0;
		void setPosition(int x, int y);
		Dimension getPosition();
		float getRange();
		void setRange(float r);
		void afficher(ostream &s);
		
	private:
		float range;
		Dimension dim;
}





#endif
