#include "Narvolt.h"

Narvolt::Narvolt(int v, int d, float r, int x, int y, int p, int t, Carte* c,int rb, float re):Tour(v, d, r, x, y, p, t, c)
{
}

Narvolt::~Narvolt()
{
}

void Narvolt::attaquer()
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
				if (faireDegat())
				{
					int j = 1;
					while (sqrt(carre(map->getCoordonnee(i).x - map->getCoordonnee(i - j).x) + carre(map->getCoordonnee(i).y - map->getCoordonnee(i - j).y)) <= rangeElectricte and j > rebond)
					{
						faireDegat();
						j++;
					}
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

bool Narvolt::ameliorerRange()
{
		
	if(attaque == true)
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

bool Narvolt::ameliorerDegat()
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
