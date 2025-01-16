#include "Carte.h"

bool Carte::ajouterTour(Tour* ptr)
{
	if(ptr == nullptr) return FALSE;
	tableau.push_back(ptr);
	return TRUE;
}
