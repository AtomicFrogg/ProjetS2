#include "EnsembleEnnemie.h"

bool EnsembleEnnemie::ajouterEnnemie(Ennemie* mob)
{
	if(mob == nullptr) return FALSE;
	tableau.push_back(mob);
	return TRUE;
}

bool EnsembleEnnemie::retirerEnnemie(int index)
{
	if(index >= 0 and index < tableau.size())
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



void EnsembleEnnemie::reinitialiser()
{
	for(int i = 0; i < getTaille(); i++)
	{
		retirerEnnemie(i);
	}
	tableau.clear();
}

int EnsembleEnnemie::getTaille()
{
	return tableau.size();
}


Ennemie* EnsembleEnnemie::getEnnemie(int index)
{
	return tableau.at(index);
}

int EnsembleEnnemie::getPosition(int index)
{
	return getEnnemie(index)->getPosition();
}

void EnsembleEnnemie::setPosition(int index, int pos)
{
	getEnnemie(index)->setPosition(pos);
}

Dimension EnsembleEnnemie::getCoordonnee(int index)
{
	return getEnnemie(index)->getCoordonnee();
}

void EnsembleEnnemie::setCoordonnee(int index, Dimension coord)
{
	getEnnemie(index)->setCoordonnee(coord);
}














