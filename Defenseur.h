#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include "dimension.h"
#include <iostream>
using namespace std;

class Defenseur
{
	public:
		Defenseur(int d = 1, float r = 1, int x = 0, int y = 0, int va = 10);
		virtual ~Defenseur();
		virtual void attaquer() = 0;
		void setPosition(int x, int y);
		Dimension getPosition();
		float getRange();
		void setRange(float r);
		virtual void afficher(ostream &s);
		int getDegat();
		void setDegat(int d);
		int getCompteurAttaque();
		void setCompteurAttaque(int c);
		int getVitesseAttaque();
		void setVitesseAttaque(int v);

	private:
		float range;
		Dimension dim;
		int degat;
		int vitesseAttaque;
		int compteurAttaque;
	
	protected:
		bool attaque;
};





#endif
