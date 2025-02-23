#include "EnsembleTour.h"

bool EnsembleTour::ajouterTour(Tour* nouvelleTour)
{
	if(nouvelleTour == nullptr) return false;
	tableau.push_back(nouvelleTour);
	return getTaille();
}

bool EnsembleTour::retirerTour(int index)
{
	if(index >= 0 && index < tableau.size())
	{
		delete tableau.at(index);
		tableau.erase(tableau.begin() + index);
		return true;

	}
	else{
		return false;
	}
}

bool EnsembleTour::reinitialiser()
{
	for(int i = 0; i < getTaille(); i++)
	{
		retirerTour(i);
	}
	tableau.clear();
	return true;
}

int EnsembleTour::getTaille()
{
	return tableau.size();
}


Tour* EnsembleTour::getTour(int index)
{
	return tableau.at(index);
}

void EnsembleTour::afficher(ostream& s)
{
	cout << "ENSEMBLE DE TOUR" << endl;
	if (getTaille() != 0)
	{ 
		for (int i = 0; i < getTaille(); i++)
		{
			getTour(i)->afficher(s);
		}
	}
	else
	{
		s << "Il n\'y a pas de tour" << endl;
	}
	
}

int EnsembleTour::getPrix(int index)
{
	return getTour(index)->getPrix();
}

void EnsembleTour::setPrix(int index,int p)
{
	getTour(index)->setPrix(p);
}

int EnsembleTour::getTier(int index)
{
	return getTour(index)->getTier();
}

void EnsembleTour::setTier(int index, int t)
{
	getTour(index)->setTier(t);
}

void EnsembleTour::setVitesse(int index,int v)
{
	getTour(index)->setVitesse(v);
}

int EnsembleTour::getVitesse(int index)
{
	return getTour(index)->getVitesse();
}


void EnsembleTour::attaquer()
{
	for (int i = 0; i < getTaille(); i++)
	{
		getTour(i)->attaquer();
	}
}

bool EnsembleTour::ameliorerRange(int index)
{
	return getTour(index)->ameliorerRange();
}

bool EnsembleTour::ameliorerDegat(int index)
{
	return getTour(index)->ameliorerDegat();
}











