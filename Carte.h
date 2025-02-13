#pragma once
#include "EnsembleEnemie.h"
#include "Enemie.h"
#include <iostream>

const int HAUTEUR = 15;
const int LARGEUR = 30;

class Carte
{
public:
	Carte();
	void afficher(ostream& s);

	bool lancerVague(int index);

	int getVie();
	int getArgent();
	void setVie(int v);
	void setArgent(int a);

	EnsembleEnemie* getEnnemie();
	bool ajouterEnnemie(Enemie* ptr);
	bool retirerEnnemie(int index);

	void reinitialiserEnnemie();
	int getTailleEnnemie();

private:
	int map[HAUTEUR][LARGEUR];
	int vie;
	int argent;
	EnsembleEnemie tableauEnnemie;
};

