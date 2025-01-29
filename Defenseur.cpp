#include "Defenseur.h"
using namespace std;

Defenseur::Defenseur(int d,float r, int x, int y):range(r),degat(d)
{
	dim.x = x;
	dim.y = y;
	attaque = true;
	compteurAttaque = 0;
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
	range = r;
}


void Defenseur::setPosition(int x, int y)
{
	dim.x = x;
	dim.y = y;
}

Dimension Defenseur::getPosition()
{
	return dim;
}

void Defenseur::afficher(ostream &s)
{
	s << "Defenseur (range = " << range << ", x = " << dim.x << ", y = " << dim.y << ")" << endl;
}


