#include "Carte.h"

Carte::Carte(int v, int a):vie(v),argent(a)
{
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 0; j < LARGEUR; j++) 
		{
			map[i][j] = 0;
		}
	}
}
/*
bool Carte::ajouterTour(Tour* ptr)
{
	if(ptr == nullptr) return false;
	tableauTour.ajouterTour(ptr);
	return true;
}

bool Carte::vendreTour(int index)
{
	if(index >= 0 && index < tableauTour.getTaille())
	{
		this->setArgent(this->getArgent() - tableauTour.retirerTour(index));
		return true;
	}
	else
	{
		return false;
	}
}
*/



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
	cout << "argent: " << getArgent() << " vie: " << getVie() << endl;
}



bool Carte::ajouterEnnemie(Ennemie* ptr)
{
	if (ptr == nullptr) return false;
	tableauEnnemie.ajouterEnnemie(ptr);
	return true;
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

EnsembleEnnemie* Carte::getEnnemie()
{
	return &tableauEnnemie;
}


/*bool Carte::ajouterEnnemie(Ennemie* mob)
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

Dimension Carte::getCoordonnee(int index)
{
	if(index >= 0 && index < getTailleEnnemie()) return tableauEnnemie.getCoordonnee(index);
	Dimension autre;
	autre.x = -1;
	autre.y = -1;
	return autre;
}

int Carte::getVieEnnemie(int index)
{
	return getEnnemie()->getVie(index);
}



int carre(int x)
{
	return x * x;
}