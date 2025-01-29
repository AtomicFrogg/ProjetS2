#include "Tour.h"
using namespace std;

Tour::Tour(int d,float r, int x, int y, int p, int t, Joueur* j):Defenseur(d,r, x, y), prix(p),tier(t),player(j)
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






