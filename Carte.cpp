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
	if(index >= 0 && index < tableauTour.getTaille())
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


void Carte::afficher(ostream& s)
{

}



bool Carte::ajouterEnnemie(Enemie* ptr)
{
	if (ptr == nullptr) return FALSE;
	tableauEnnemie.ajouterEnnemie(ptr);
	return TRUE;
}

bool Carte::retirerEnnemie(int index)
{
	bool result = false;
	if (index < this->tableauEnnemie.getTaille() and index > 0)
	{
		tableauEnnemie.retirerEnnemie(index);
		result = true;

	}
	return result;
}

EnsembleEnemie* Carte::getEnnemie()
{
	return &tableauEnnemie;
}


/*bool Carte::ajouterEnnemie(Enemie* mob)
{
	return tableauEnnemie.ajouterEnnemie(mob);
}*/

/*bool Carte::retirerEnnemie(int index)
{
	return tableauEnnemie.retirerEnnemie(index);
}*/

void Carte::reinitialiserEnnemie()
{
	tableauEnnemie.reinitialiser();
}


int Carte::getTailleEnnemie()
{
	return tableauEnnemie.getTaille();
}
