#include "Ennemie.h"


Ennemie::Ennemie(int v, int vit, int pos, int r) :vie(v), vitesse(vit), position(pos), revenu(r)
{
	coordonnee.x = 0;
	coordonnee.y = 0;
}

Ennemie::~Ennemie()
{
	//carte->setArgent(carte->getArgent + revenu);
}

int Ennemie::getVie()
{
	return vie;
}

int Ennemie::getVitesse()
{
	return vitesse;
}

int Ennemie::getPosition()
{
	return position;
}


void Ennemie::setVie(int v)
{
	if (v > 0)
	{
		vie = v;
	}
	else
	{

	}
}


void Ennemie::setCoordonnee(Dimension coord)
{
	coordonnee = coord;
}

void Ennemie::accelerer() {
	setPosition(getPosition() * vitesse);
}

Dimension Ennemie::getCoordonnee()
{
	return coordonnee;
}

int Ennemie::getRevenu()
{
	return revenu;
}

void Ennemie::setRevenu(int r)
{
	if (r >= 0)
	{
		revenu = r;
	}
	else
	{
		revenu = -r;
	}
}

