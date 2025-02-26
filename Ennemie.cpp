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

void Ennemie::gauche(int val) {
	coordonnee.x += val;
}
void Ennemie::descendre(int val) {
	coordonnee.y -= val;
}
void Ennemie::monter(int val) {
	coordonnee.y += val;
}

void Ennemie::deplacement() {
	//gauche
	gauche(3);
	//descendre
	descendre(1);
	//gauche
	gauche(1);
	//descendre
	descendre(1);
	//gauche
	gauche(2);
	//descendre
	descendre(2);
	//gauche
	gauche(6);
	//monter
	monter(6);
	//gauche
	gauche(5);
	//descendre
	descendre(3);
	//gauche
	gauche(7);
	//monter
	monter(2);
	//gauche
	gauche(5);
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

