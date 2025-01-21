#include "Defenseur.h"
using namespace std;

Defenseur::Defenseur(float r, int x, int y, int p, int t):range(r),prix(p),tier(t)
{
	dim.x = x;
	dim.y = y;
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
	s << "Defenseur (range = " << range << ", x = " << dim.x << ", y = " << dim.y << ", cout = " << prix << ", tier = " << tier << ")" << endl;
}


