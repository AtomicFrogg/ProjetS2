#include "../Header/Narvolt.h"

Narvolt::Narvolt(int d, float r, int x, int y, int va, int p, int t, Carte* c, int rb, float re) :Tour(d, r, x, y, va, p, t, c), rebond(rb), rangeElectricte(re)
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
				faireDegat(i);
				setCompteurAttaque(getVitesseAttaque());
				int j = 1;
				while (i >= j && sqrt(carre(map->getCoordonnee(i - j + 1).x - map->getCoordonnee(i - j).x) + carre(map->getCoordonnee(i - j + 1).y - map->getCoordonnee(i - j).y)) <= rangeElectricte && j > rebond)
				{
					if ( i - j >= 0) faireDegat(i);
					j++;
				}
				setCompteurAttaque(getVitesseAttaque());
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


bool Narvolt::ameliorerRange()
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

bool Narvolt::ameliorerDegat()
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
