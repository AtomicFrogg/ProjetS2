#include "Defenseur.h"

Defenseur::Defenseur(int d, float r, int x, int y, int va) :range(r), degat(d), vitesseAttaque(va)
{
	dim.x = x;
	dim.y = y;
	attaque = true;
	compteurAttaque = 1;
}

Defenseur::~Defenseur()
{

}

float Defenseur::getRange()
{
	return range;
}


void Defenseur::setRange(float r)
{
	if (r >= 0) range = r;
}


void Defenseur::setPosition(int x, int y)
{
	if (x >= 0) dim.x = x;
	if (y >= 0) dim.y = y;
}

Dimension Defenseur::getPosition()
{
	return dim;
}

void Defenseur::afficher(ostream& s)
{
	s << "Defenseur (range = " << range << ", x = " << dim.x << ", y = " << dim.y << ")" << endl;
}


int Defenseur::getDegat()
{
	return degat;
}

void Defenseur::setDegat(int d)
{
	degat = d;
}

int Defenseur::getCompteurAttaque()
{
	return compteurAttaque;
}
void Defenseur::setCompteurAttaque(int c)
{
	compteurAttaque = c;
}
int Defenseur::getVitesseAttaque()
{
	return vitesseAttaque;
}

void Defenseur::setVitesseAttaque(int v)
{
	vitesseAttaque = v;
}
