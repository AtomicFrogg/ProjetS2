#include "Carte.h"

bool Carte::ajouterTour(Tour* ptr)
{
	if(ptr == nullptr) return FALSE;
	tableauTour.ajouterTour(ptr);
	return TRUE;
}


