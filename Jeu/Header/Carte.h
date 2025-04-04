#pragma once
#include "../../Ennemis/Header/EnsembleEnnemie.h"
#include "../../Ennemis/Header/Ennemie.h"
#include <iostream>
#include <cstdlib>
#include "DonneesEnnemies.h"

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
	bool ajouterRequin(int c);
	bool ajouterSaumon(int c);
	void debutEnnemie(int nbr);

	void reinitialiserEnnemie();
	int getTailleEnnemie();

	Dimension getCoordonnee(int index);
	int getVieEnnemie(int index);

	DonneesEnnemies Requin;
	DonneesEnnemies Saumon;
	DonneesEnnemies Baleine;

private:
	int map[HAUTEUR][LARGEUR];
	int vie;
	int argent;
	EnsembleEnnemie tableauEnnemie;
};

int carre(int x);

