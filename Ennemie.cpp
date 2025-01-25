#include "Ennemie.h"
using namespace std;

Ennemie::Ennemie(int v, int vit, int pos):vie(v), vitesse(vit), position(pos)
{
	coordonnee.x = 0;
	coordonnee.y = 0;
}

Ennemie::~Ennemie()
{
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
	if(v > 0)
	{
		vie = v;
	}
	else
	{
		
	}
}

void Ennemie::setVitesse(int v)
{
	vitesse = v;
}

void Ennemie::setCoordonnee(Dimension coord)
{
	coordonnee = coord;
}


Dimension Ennemie::getCoordonnee()
{
	return coordonnee;
}









