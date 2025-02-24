#include "EnsembleEnemie.h"

bool EnsembleEnemie::ajouterEnnemie(Enemie* mob)
{
	if (mob == nullptr) return FALSE;
	tableau.push_back(mob);
	return TRUE;
}

bool EnsembleEnemie::retirerEnnemie(int index)
{
	if (index >= 0 and index < tableau.size())
	{
		delete tableau.at(index);
		tableau.erase(tableau.begin() + index);
		tableau.shrink_to_fit();
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



void EnsembleEnemie::reinitialiser()
{
	for (int i = 0; i < getTaille(); i++)
	{
		retirerEnnemie(i);
	}
	tableau.clear();
}

int EnsembleEnemie::getTaille()
{
	return tableau.size();
}


Enemie* EnsembleEnemie::getEnnemie(int index)
{
	return tableau.at(index);
}

int EnsembleEnemie::getPosition(int index)
{
	return getEnnemie(index)->getPosition();
}

void EnsembleEnemie::setPosition(int index, int pos)
{
	getEnnemie(index)->setPosition(pos);
}

Dimension EnsembleEnemie::getCoordonnee(int index)
{
	return getEnnemie(index)->getCoordonnee();
}

void EnsembleEnemie::setCoordonnee(int index, Dimension coord)
{
	getEnnemie(index)->setCoordonnee(coord);
}
