#include "Tour.h"

Tour::Tour(int d, float r, int x, int y, int va, int p, int t, Carte* c) :Defenseur(d, r, x, y, va), prix(p), tier(t), map(c)
{
}

Tour::~Tour()
{

}

void Tour::afficher(ostream& s)
{
	s << "Tour (range = " << getRange() << ", Degat = " << getDegat() << ", x = " << getPosition().x << ", y = " << getPosition().y << ", cout = " << prix << ", tier = " << tier << ")" << endl;
}


void Tour::setTier(int t)
{
	if (t >= 0) tier = t;
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
	if (p >= 0) prix = p;
}

void Tour::setVitesse(int v)
{
	if (v >= 0) setVitesseAttaque(v);
}


int Tour::getVitesse()
{
	return getVitesseAttaque();
}

bool Tour::faireDegat(int i)
{
	int vie = (map->getVieEnnemie(i) - getDegat());
	cout << vie;
	if (vie > 0)
	{
		map->getEnnemie()->getEnnemie(i)->setVie(vie);

		setCompteurAttaque(getVitesseAttaque());
		return true;
	}
	else
	{
		cout << "HAAAAAAAAAAAAAAAAAAAAAAAAAA";
		map->retirerEnnemie(i);
		return false;
	}
}