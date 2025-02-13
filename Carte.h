#ifndef CARTE_H
#define CARTE_H

#include "EnsembleEnnemie.h"

const int HAUTEUR = 15;
const int LARGEUR = 30;

class Carte
{
	public:
		Carte();
		void afficher(ostream &s);

		bool lancerVague(int index);
		
		int getVie();
		int getArgent();
		void setVie(int v);
		void setArgent(int a);
		
		EnsembleEnnemie* getEnnemie();
        bool ajouterEnnemie(Ennemie* ptr);
		bool retirerEnnemie(int index);
		
		bool ajouterEnnemie(int index, Ennemie* mob);
		bool retirerEnnemie(int index);
		void reinitialiserEnnemie();
		int getTailleEnnemie();
		
	private:
		int map[HAUTEUR][LARGEUR];
		int vie;
		int argent;
		EnsembleEnnemie tableauEnnemie;

};







#endif
