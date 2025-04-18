#include "../Header/TourBase1.h"

TourBase1::TourBase1(int d, float r, int x, int y, int va, int p, int t, Carte* c) :Tour(d, r, x, y, va, p, t, c)
{
}


TourBase1::~TourBase1()
{
}


void TourBase1::attaquer()
{

	if (attaque == true)
	{
		double distance;
		for (int i = 0; i < map->getTailleEnnemie(); i++)
		{
			distance = sqrt(carre(map->getCoordonnee(i).x - this->getPosition().x) + carre(map->getCoordonnee(i).y - this->getPosition().y));
			if (distance < getRange())
			{
				this->attaque = false;
				faireDegat(i);
				setCompteurAttaque(getVitesseAttaque());
				break;
			}
		}
	}
	else
	{
		setCompteurAttaque(getCompteurAttaque() - 1);
		if (getCompteurAttaque() <= 0)
		{
			attaque = true;
		}

	}
}


bool TourBase1::ameliorerRange()
{
	if (getTier() < MAX_TIER && this->map->getArgent() >= (200 * getRange()))
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
	if (getTier() < MAX_TIER && map->getArgent() >= (400 * getDegat()))
	{
		this->map->setArgent(this->map->getArgent() - (400 * getDegat()));
		setDegat(getDegat() * 2);
		setTier(getTier() + 1);

		return true;
	}
	return false;
}
