#pragma once
#include "EnsembleEnnemie.h"
#include "Ennemie.h"
#include <iostream>

const int HAUTEUR = 15;
const int LARGEUR = 30;

class Carte
{
public:
	Carte(int v = 100, int a = 400);
	void afficher(ostream& s);

	bool lancerVague(int index);

	int getVie();
	int getArgent();
	void setVie(int v);
	void setArgent(int a);

	EnsembleEnnemie* getEnnemie();
	bool ajouterEnnemie(Ennemie* ptr);
	bool retirerEnnemie(int index);

	void reinitialiserEnnemie();
	int getTailleEnnemie();
	Dimension getCoordonnee(int index);



private:
	int map[HAUTEUR][LARGEUR];
	int vie;
	int argent;
	EnsembleEnnemie tableauEnnemie;
};

int carre(int x);