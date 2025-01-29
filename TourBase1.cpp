#include "TourBase1.h"


TourBase1::TourBase1(int d,float r, int x, int y, int p, int t, Carte* c):Tour(d,r,x,y,p,t,c)
{}


TourBase1::~TourBase1()
{}



void TourBase1::attaquer()
{
	double distance = 1000;
	for(int i = 0; i < carte->getEnnemie[i]->getTaille(); i++)
	{
		distance = sqrt(carre(carte->getEnnemie[i]->getPosition().x - this->dim.x) + carre(carte->getEnnemie[i]->getPosition().y - this->dim.y);
		if(this->distance < carte->getEnnemie[i]->getRange())
		{
			if ((int vie = (carte->getEnnemie[i]->getVie - this->degat)) > 0)
			{
				carte->getEnnemie[i]->setVie(vie);
				break
			}
			
			
		}
	}
}


bool TourBase1::ameliorerRange()
{
	if(tier < 4 and carte->getArgent() >= (200 * range))
	{
		range = range + 1;
		tier++;
		return true;
	}
	return false;
}


bool TourBase1::ameliorerDegat()
{
	if(tier < 4 and carte->getArgent() >= (400 * degat))
	{
		degat = degat * 2;
		tier++;
		return true;
	}
	return false;
}


















