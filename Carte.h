#ifndef CARTE_H
#define CARTE_H

#include "EnsembleTour.h"
#include "EnsembleEnnemie.h"

const int HAUTEUR = 15;
const int LARGEUR = 30;

class Carte
{
	public:
		Carte();
		bool ajouterTour(Tour* ptr);
		bool vendreTour(int index);
		
		
		
		
		bool ajouterEnnemie(Ennemie* ptr);
		bool lancerVague(int index);
		
		int getVie();
		int getArgent();
		void setVie(int v);
		void setArgent(int a);
		
	private:
		int map[HAUTEUR][LARGEUR];
		int vie;
		int argent;
		EnsembleTour tableauTour;
		EnsembleEnnemie tableauEnnemie;
};







#endif
