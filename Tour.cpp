#include "Tour.h"
using namespace std;

Tour::Tour(int v, int d,float r, int x, int y, int p, int t, Carte* c):Defenseur(d,r, x, y), prix(p),tier(t),vitesse(v)
{
}

Tour::~Tour()
{
	
}

void Tour::afficher(ostream &s)
{
	s << "Tour (range = " << getRange() << ", x = " << getPosition().x << ", y = " << getPosition().y << ", cout = " << prix << ", tier = " << tier << ")" << endl;
}


void Tour::setTier(int t)
{
	if(t >= 0) tier = t;
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
	if(p >= 0) prix = p;
}

void Tour::setVitesse(int v)
{
	if(v >= 0) vitesse = v;
}


int Tour::getVitesse()
{
	return vitesse;
}








