#include "Tour.h"
using namespace std;

Tour::Tour(float r, int x, int y, int p, int t):range(r),prix(p),tier(t)
{
	dim.x = x;
	dim.y = y;
}

Tour::~Tour()
{
	
}

float Tour::getRange()
{
	return range;
}


void Tour::setRange(float r)
{
	range = r;
}


void Tour::setPosition(int x, int y)
{
	dim.x = x;
	dim.y = y;
}

Dimension Tour::getPosition()
{
	return dim;
}

void Tour::afficher(ostream &s)
{
	s << "Tour (range = " << range << ", x = " << dim.x << ", y = " << dim.y << ", cout = " << prix << ", tier = " << tier << ")" << endl;
}


void Tour::setTier(int t)
{
	tier = t;
}

int Tour::getTier()
{
	return tier;
}

int Tour::getPrix()
{
	return prix;
}

void Tour::setPrix(int p)
{
	prix = p;
}






