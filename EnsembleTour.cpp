#include "EnsembleTour.h"

bool EnsembleTour::ajouterTour(Tour* nouvelleTour)
{
	if(nouvelleTour == nullptr) return FALSE;
	tableau.push_back(nouvelleTour);
	return TRUE;
}

int EnsembleTour::retirerTour(int index)
{
	if(index >= 0 and index < tableau.size())
	{
		delete tableau.at(index);
		tableau.erase(tableau.begin() + index);
		tableau.shrink_to_fit();
		return TRUE;
	}
	else{
		return FALSE;
	}
}

bool EnsembleTour::reinitialiser()
{
	for(int i = 0; i < getTaille(); i++)
	{
		retirerTour(i);
	}
	tableau.clear();
	return TRUE;
}

int EnsembleTour::getTaille()
{
	return tableau.size();
}


Tour* EnsembleTour::getTour(int index)
{
	return tableau.at(index);
}


















