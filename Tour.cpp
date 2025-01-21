#include "Tour.h"
using namespace std;

Tour::Tour(float r, int x, int y):range(r)
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

void attaquer();

void afficher(ostream &s)
{
	s << "Tour (range = " << range << ", x = " << dim.x << ", y = " << dim.y << ", cout = " << prix << endl;
}








