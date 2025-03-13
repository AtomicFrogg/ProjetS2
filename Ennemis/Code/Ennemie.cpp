#include "../Header/Ennemie.h"


Ennemie::Ennemie(int v, int vit, int r, int d, int cpt) :vie(v), vitesse(vit), revenu(r), degat(d)
{
	position = 0;
	compteur = cpt;
	coordonnee.x = 0;
	coordonnee.y = 9;
}

Ennemie::~Ennemie()
{
	//carte->setArgent(carte->getArgent + revenu);
}

bool Ennemie::deplacement() {
	if (compteur == 0) {
		compteur = vitesse;
		return true;
	}
	else {
		compteur--;
		return false;
	}
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

int Ennemie::getEtat() {
	return etat;
}

int Ennemie::getDegat() {
	return degat;
}
void Ennemie::setPosition(int p) {
	if (p > 0) {
		position = p;
	}
}

void Ennemie::setVitesse(int v)
{
	vitesse = v;
}
