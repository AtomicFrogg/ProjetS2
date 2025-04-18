#pragma once
#include "../../Jeu/Header/dimension.h"
//#include "Carte.h"

class Ennemie
{
public:
	Ennemie(int v = 100, int vit = 1, int r = 2, int d = 3,int cpt = 0, int type = 0);
	virtual ~Ennemie();
	int getVie();
	int getVitesse();
	int getPosition();
	void setVie(int v);
	void setVitesse(int v);
	void setPosition(int p);
	int getDegat();
	int getEtat();
	Dimension getCoordonnee();
	void setCoordonnee(Dimension coord);
	void setRevenu(int r);
	int getRevenu();
	int getType();
	void accelerer();

	bool deplacement();

private:
	Dimension coordonnee;
protected:
	int vie;
	int position; // pos = 1 :top; pos = 2 : down; pos = 3: right; pos = 4: Left
	int vitesse;
	int revenu;
	int compteur;
	int degat;
	bool etat;
	int type; //1: saumon, 2: requin, 3: baleine
};
