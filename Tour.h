#ifndef TOUR_H
#define TOUR_H

#include "Carte.h"
#include "Defenseur.h"
#include "dimension.h"
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_TIER = 5;
class Tour: public Defenseur
{
	public:
		Tour(int v, int d,float r, int x, int y, int p, int t, Carte* c);
		~Tour();
		int getPrix();
		void setPrix(int p);
		int getTier();
		void setTier(int t);
		void setVitesse(int v);
		int getVitesse();
		
		virtual void afficher(ostream &s);
		virtual void attaquer() = 0;
		virtual bool ameliorerRange() = 0;
		virtual bool ameliorerDegat() = 0;
	private:
		int vitesse;
		int prix;
		int tier;
	
	protected:
		bool faireDegat();
		Carte* map; 
};




#endif


