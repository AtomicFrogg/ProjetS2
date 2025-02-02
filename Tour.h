#ifndef TOUR_H
#define TOUR_H

#include "Joueur.h"
#include "dimension.h"
#include <iostream>
using namespace std;

class Tour: public Defenseur
{
	public:
		Tour(int d,float r, int x, int y, int p, int t, Joueur* j);
		~Tour();
		int getPrix();
		void setPrix(int p);
		int getTier();
		void setTier(int t);
		virtual void afficher(ostream &s);
		
	private:
		int prix;
		int tier;
		Joueur* player;
		
};




#endif


