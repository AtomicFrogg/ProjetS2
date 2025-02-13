#include "TourBase1.h"


TourBase1::TourBase1(int d,float r, int x, int y, int p, int t, Carte& c):Tour(d,r,x,y,p,t,j)
{}


TourBase1::~TourBase1()
{}

//Yo le code ne fonctionne pas parce que c'est pas possible d'accéder aux éléments privés des autres classes

void TourBase1::attaquer()
{
	
	if(attaque == true)
	{
		double distance;
		for(int i = 0; i < map->getTaille(); i++)
		{
			distance = sqrt(carre(map->getCoordonne(i).x - this->dim.x) + carre(map->getCoordonne(i).y - this->dim.y));
			if(this->distance < this->range))
			{
				if ((int vie = (map->getVie() - this->degat)) > 0)
				{
					map->setVie(vie);
					this->attaque = false;
					this->compteurAttaque = this->vitesseAttaque;
					break
				}
				else
				{
					map->retirerEnnemie[i];
				}
			}
		}
	}
	else
	{
		compteurAttaque--;
		if (compteurAttaque == 0)
		{
			attaque = true;
		}
		
	}
}


bool TourBase1::ameliorerRange()
{
	if(tier < 4 /*and carte->getArgent() >= (200 * range)*/)
	{
		range = range + 1;
		tier++;
		return true;
	}
	return false;
}


bool TourBase1::ameliorerDegat()
{
	if(tier < 4 /*and carte->getArgent() >= (400 * degat)*/)
	{
		degat = degat * 2;
		tier++;
		return true;
	}
	return false;
}


















