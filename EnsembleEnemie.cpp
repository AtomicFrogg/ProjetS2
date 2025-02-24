#include "EnsembleEnnemie.h"

bool EnsembleEnnemie::ajouterEnnemie(Ennemie* mob)
{
	if (mob == nullptr) return false;
	tableau.push_back(mob);
	return true;
}

bool EnsembleEnnemie::retirerEnnemie(int index)
{
	if (index >= 0 and index < tableau.size())
	{
		delete tableau.at(index);
		tableau.erase(tableau.begin() + index);
		tableau.shrink_to_fit();
		return true;
	}
	else
	{
		return false;
	}
}



void EnsembleEnnemie::reinitialiser()
{
	for (int i = 0; i < getTaille(); i++)
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
	if(index >= 0 && index < getTaille()) return tableau.at(index);
	return nullptr;
}

int EnsembleEnnemie::getPosition(int index)
{
	if(index >= 0 && index < getTaille()) return getEnnemie(index)->getPosition();
	return -1;
}

void EnsembleEnnemie::setPosition(int index, int pos)
{
	if(index >= 0 && index < getTaille()) getEnnemie(index)->setPosition(pos);
}

Dimension EnsembleEnnemie::getCoordonnee(int index)
{
	if(index >= 0 && index < getTaille()) return getEnnemie(index)->getCoordonnee();
}

void EnsembleEnnemie::setCoordonnee(int index, Dimension coord)
{
	if(index >= 0 && index < getTaille()) getEnnemie(index)->setCoordonnee(coord);
}

int EnsembleEnnemie::getVie(int index)
{
	return getEnnemie(index)->getVie();
}