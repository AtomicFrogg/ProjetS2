#ifndef TOUR_H
#define TOUR_H

#include "Carte.h"
#include "dimension.h"
#include "Defenseur.h"
#include <iostream>
using namespace std;

class Tour: public Defenseur
{
	public:
		Tour(int v,int d,float r, int x, int y, int p, int t, Carte* c);
		~Tour();
		int getPrix();
		void setPrix(int p);
		int getTier();
		void setTier(int t);
		void setVitesse(int v);
		int getVitesse();
		
		virtual void afficher(ostream &s);
		
	private:
		int prix;
		int tier;
		int vitesse;
};




#endif


