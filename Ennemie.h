#pragma once
#include "dimension.h"
//#include "Carte.h"

class Ennemie
{
public:
	Ennemie(int v = 100, int vit = 1, int pos = 5, int r = 2);
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

private:
	Dimension coordonnee;
protected:
	int vie;
	int position;
	int vitesse;
	int revenu;
};
