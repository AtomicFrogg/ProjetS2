#include "TourBase1.h"


TourBase1::TourBase1(int d,float r, int x, int y, int p, int t, Joueur* j):Tour(d,r,x,y,p,t,j)
{}


TourBase1::~TourBase1()
{}



void TourBase1::attaquer()
{
	
	if(attaque == true)
	{
		double distance;
		for(int i = 0; i < player->getEnnemie[i]->getTaille(); i++)
		{
			distance = sqrt(carre(player->getEnnemie[i]->getPosition().x - this->dim.x) + carre(player->getEnnemie[i]->getPosition().y - this->dim.y));
			if(this->distance < player->getEnnemie[i]->getRange())
			{
				if ((int vie = (player->getEnnemie[i]->getVie - this->degat)) > 0)
				{
					player->getEnnemie[i]->setVie(vie);
					this->attaque = false;
					this->compteurAttaque = this->vitesseAttaque;
					break
				}
				else
				{
					player->getEnnemie[i]->retirerEnnemie[i];
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


















