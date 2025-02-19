#include "TourBase1.h"

TourBase1::TourBase1(int v, int d,float r, int x, int y, int p, int t, Carte* c):Tour(v,d,r,x,y,p,t,c)
{}


TourBase1::~TourBase1()
{}

//Yo le code ne fonctionne pas parce que c'est pas possible d'accéder aux éléments privés des autres classes

void TourBase1::attaquer()
{
	
	if(attaque == true)
	{
		double distance;
		for(int i = 0; i < map->getTailleEnnemie(); i++)
		{
			distance = sqrt(carre(map->getCoordonnee(i).x - this->getPosition().x) + carre(map->getCoordonnee(i).y - this->getPosition().y));
			if(distance < getRange())
			{
				this->attaque = false;
				int vie = (map->getVie() - getDegat());
				if (vie > 0)
				{
					map->setVie(vie);
				
					setCompteurAttaque(getVitesseAttaque());
					break;
				}
				else
				{
					map->retirerEnnemie(i);
					break;
				}
			}
		}
	}
	else
	{
		setCompteurAttaque(getCompteurAttaque() - 1);
		if (getCompteurAttaque() == 0)
		{
			attaque = true;
		}
		
	}
}


bool TourBase1::ameliorerRange()
{
	if(getTier() < MAX_TIER and this->map->getArgent() >= (200 * getRange()))
	{
		this->map->setArgent(this->map->getArgent() - (200 * getRange()));
		setRange(getRange() + 1);
		setTier(getTier() + 1);

		return true;
	}
	return false;
}


bool TourBase1::ameliorerDegat()
{
	if(getTier() < MAX_TIER and map->getArgent() >= (400 * getDegat()))
	{
		this->map->setArgent(this->map->getArgent() - (400 * getDegat()));
		setDegat(getDegat() * 2);
		setTier(getTier() + 1);
		
		return true;
	}
	return false;
}


















