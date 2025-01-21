#include "EnsembleEnnemie.h"

bool EnsembleEnnemie::ajouterEnnemieFin(Ennemie* mob)
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
	for(int i = 0; i < tableau.getTaille(); i++)
	{
		tableau.retirerTour(i);
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
















