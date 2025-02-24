#include "Canonnier.h"

Canonnier::Canonnier(int d, float r, int x, int y, int va, int p, int t, Carte* c, float re) :Tour(d, r, x, y,va, p, t, c), rangeExplosion(re)
{
}

Canonnier::~Canonnier()
{
}

void Canonnier::attaquer()
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
				int j = 1;
				while (i >= j and sqrt(carre(map->getCoordonnee(i).x - map->getCoordonnee(i - j).x) + carre(map->getCoordonnee(i).y - map->getCoordonnee(i - j).y)) <= rangeExplosion)
				{
					faireDegat(i);
					j++;
				}
				j = -1;
				while (i >= -j and sqrt(carre(map->getCoordonnee(i).x - map->getCoordonnee(i - j).x) + carre(map->getCoordonnee(i).y - map->getCoordonnee(i - j).y)) <= rangeExplosion)
				{
					faireDegat(i);
					j--;
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


bool Canonnier::ameliorerRange()
{

	if (getTier() < MAX_TIER and this->map->getArgent() >= (200 * getRange()))
	{
		this->map->setArgent(this->map->getArgent() - (200 * getRange()));
		setRange(getRange() + 1);
		setTier(getTier() + 1);

		return true;
	}
	return false;
}

bool Canonnier::ameliorerDegat()
{
	if (getTier() < MAX_TIER and map->getArgent() >= (400 * getDegat()))
	{
		this->map->setArgent(this->map->getArgent() - (400 * getDegat()));
		setDegat(getDegat() * 2);
		setTier(getTier() + 1);

		return true;
	}
	return false;
}

