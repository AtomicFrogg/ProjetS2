#include "EnsembleTour.h"

bool EnsembleTour::ajouterTour(Tour* nouvelleTour)
{
	if(nouvelleTour == nullptr) return FALSE;
	tableau.push_back(nouvelleTour);
	return TRUE;
}

bool EnsembleTour::retirerTour(int index)
{
	if(index >= 0 && index < tableau.size())
	{
		delete tableau.at(index);
		tableau.erase(tableau.begin() + index);
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

void EnsembleTour::afficher(ostream& s)
{	
	cout << "ENSEMBLE DE TOUR" << endl;
	for (int i = 0; i < getTaille(); i++)
	{
		getTour(i)->afficher(s);
	}
}
















