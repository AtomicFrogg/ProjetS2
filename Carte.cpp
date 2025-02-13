#include "Carte.h"

/*
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
*/


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

void Carte::setVie(int v)
{
	vie = v;
}

void Carte::setArgent(int a)
{
	argent = a;
}


void Carte::afficher(ostream &s)
{

}



bool Carte::ajouterEnnemie(Ennemie* ptr)
{
	if(ptr == nullptr) return FALSE;
	tableauEnnemie.ajouterEnnemie(ptr);
	return TRUE;
}

bool Carte::retirerEnnemie(int index)
{
	if(index < this->tableauEnnemie.getTaille() and index > 0)
	{
		tableauEnnemie.retirerEnnemie(index);
		
	}
}

EnsembleEnnemie* Carte::getEnnemieTaille()
{
	return &tableauEnnemie;
}


bool Carte::ajouterEnnemie(Ennemie* mob)
{
	return tableauEnnemie.ajouterEnnemie(mob);
}

bool Carte::retirerEnnemie(int index)
{
	return tableauEnnemie.retirerEnnemie(index);
}

void Carte::reinitialiserEnnemie()
{
	tableauEnnemie.reinitialiser();
}


int Carte::getTailleEnnemie()
{
	return tableauEnnemie.getTaille();
}











