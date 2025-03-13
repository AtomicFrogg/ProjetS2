#pragma once
#include "EnsembleEnnemie.h"
#include "Ennemie.h"
#include "EnnemieBaleine.h"
#include "EnnemieBaltimore.h"
#include "EnnemieRequin.h"
#include <iostream>
#include <cstdlib>

const int HAUTEUR = 15;
const int LARGEUR = 30;
using namespace std;
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
	void moveEnnemie(int x, int y);
	void deplacementEnnemie();
	void attaqueEnnemie();
	bool ajouterBaleine(int c);
	bool ajouterEspadon(int c);
	bool ajouterPerchaude(int c);
	void debutEnnemie(int nbr);

	void reinitialiserEnnemie();
	int getTailleEnnemie();

	Dimension getCoordonnee(int index);


	int getVieEnnemie(int index);

private:
	int map[HAUTEUR][LARGEUR];
	int vie;
	int argent;
	EnsembleEnnemie tableauEnnemie;
};

int carre(int x);

