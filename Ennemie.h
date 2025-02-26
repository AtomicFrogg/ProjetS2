#pragma once
#include "dimension.h"
//#include "Carte.h"

class Ennemie
{
public:
	Ennemie(int v = 100, int vit = 1, int r = 2);
	virtual ~Ennemie();
	int getVie();
	int getVitesse();
	int getPosition();
	void setVie(int v);
	virtual void setVitesse(int v) = 0;
	virtual void setPosition(int p) = 0;
	virtual int getDegat() = 0;
	Dimension getCoordonnee();
	void setCoordonnee(Dimension coord);
	void setRevenu(int r);
	int getRevenu();
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
};
