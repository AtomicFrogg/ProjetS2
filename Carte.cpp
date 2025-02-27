#include "Carte.h"


Carte::Carte(int v, int a) :vie(v), argent(a)
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

void Carte::deplacementEnnemie() {
	tableauEnnemie.deplacementEnnemie();
}

bool Carte::lancerVague(int index)
{
	deplacementEnnemie();
	return 0;
}

void Carte::attaqueEnnemie() {
	for (int i = 0;i < tableauEnnemie.getTaille();i++) {
		setVie(getVie() - tableauEnnemie.getEnnemie(i)->getDegat());
	}
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
	for (int i = 0;tableauEnnemie.getTaille();i++) {
		s << "argent: " << tableauEnnemie.getEnnemie(i)->getRevenu() << " vie: " << tableauEnnemie.getEnnemie(i)->getVie() << endl;
	}
}

bool Carte::ajouterBaleine(int c)
{
	Ennemie* newEnnemie = new Ennemie(400, 3, 500, c);
	ajouterEnnemie(newEnnemie);
	return 1;
}

bool Carte::ajouterPerchaude(int c)
{
	Ennemie* newEnnemie = new Ennemie(20, 1, 50, 5, c);
	ajouterEnnemie(newEnnemie);
	return 1;
}

bool Carte::ajouterEspadon(int c)
{
	Ennemie* newEnnemie = new Ennemie(100, 2, 100, c);
	ajouterEnnemie(newEnnemie);
	return 1;
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
	if (index < this->tableauEnnemie.getTaille() and index >= 0)
	{
		setArgent(getArgent() + tableauEnnemie.getEnnemie(index)->getRevenu());
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
	if (index >= 0 && index < getTailleEnnemie()) return tableauEnnemie.getCoordonnee(index);
	Dimension autre;
	autre.x = -1;
	autre.y = -1;
	return autre;
}

void Carte::moveEnnemie(int x, int y) {

	tableauEnnemie.moveEnnemie(x, y);
}


int Carte::getVieEnnemie(int index)
{
	return getEnnemie()->getEnnemie(index)->getVie();
}

int carre(int x)
{
	return x * x;
}


void Carte::debutEnnemie(int nbr)
{
	int alea;
	for(int i = 0; i < 3 * nbr; i = i+3)
	{
		alea = rand() % 3;
		switch (alea)
		{
		case 0:
			ajouterBaleine(i);
			break;
		case 1:
			ajouterEspadon(i);
			break;
		case 2:
			ajouterPerchaude(i);
			break;
		default:
			break;
		}
	}
}

