#ifndef TOUR_H
#define TOUR_H

#include "Carte.h"
#include "Defenseur.h"
#include "dimension.h"
#include <iostream>
#include <cmath>
using namespace std;

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
		
	private:
		int vitesse;
		int prix;
		int tier;
	
	protected:
		Carte* map; 
};




#endif


