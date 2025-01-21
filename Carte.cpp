#include "Carte.h"

bool Carte::ajouterTour(Tour* ptr)
{
	if(ptr == nullptr) return FALSE;
	tableauTour.ajouterTour(ptr);
	return TRUE;
}

bool Carte::vendreTour(int index)
{
	if(index >= 0 and index < tableauTour.getTaille())
	{
		this->setArgent(this->getArgent() - tableauTour.retirerTour(index));
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool Carte::ajouterEnnemie(Ennemie* ptr)
{
	if(ptr == nullptr) return FALSE;
	tableauEnnemie.ajouterEnnemie(ptr);
	return TRUE;
}


bool Carte::lancerVague(int index)
{
	return FALSE;
}

int Carte::getVie()
{
	return vie;
}

int Carte::getArgent()
{
	return argent;
}

void setVie(int v)
{
	vie = v;
}

void setArgent(int a)
{
	argent = a;
}
















