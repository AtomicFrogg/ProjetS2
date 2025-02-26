#pragma once
#include "dimension.h"
//#include "Carte.h"

class Ennemie
{
public:
	Ennemie(int v = 100, int vit = 1, int pos = 5, int r = 2,int d = 3);
	virtual ~Ennemie();
	int getVie();
	int getVitesse();
	int getPosition();
	void setVie(int v);
	void setVitesse(int v);
	void setPosition(int p);
	int getDegat();
	Dimension getCoordonnee();
	void setCoordonnee(Dimension coord);
	void setRevenu(int r);
	int getRevenu();
	void accelerer();
	void gauche(int val);
	void descendre(int val);
	void monter(int val);
	void deplacement();

private:
	Dimension coordonnee;
protected:
	int vie;
	int position;
	int vitesse;
	int revenu;
	int degat;
};
