#include "Enemie.h"

Enemie::Enemie(int v, int vit, int pos, int r) :vie(v), vitesse(vit), position(pos), revenu(r)
{
	coordonnee.x = 0;
	coordonnee.y = 0;
}

Enemie::~Enemie()
{
	//carte->setArgent(carte->getArgent + revenu);
}

int Enemie::getVie()
{
	return vie;
}

int Enemie::getVitesse()
{
	return vitesse;
}

int Enemie::getPosition()
{
	return position;
}

void Enemie::setVie(int v)
{
	if (v > 0)
	{
		vie = v;
	}
	else
	{

	}
}

void Enemie::setVitesse(int v)
{
	vitesse = v;
}

void Enemie::setCoordonnee(Dimension coord)
{
	coordonnee = coord;
}


Dimension Enemie::getCoordonnee()
{
	return coordonnee;
}

int Enemie::getRevenu()
{
	return revenu;
}

void Enemie::setRevenu(int r)
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
