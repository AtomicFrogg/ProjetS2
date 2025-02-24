#include "Joueur.h"


Joueur::Joueur(){
    nom = "Jacob";
}

Joueur::Joueur(string n){
    setNom(n);
}

Joueur::~Joueur(){
    nom = "";
}

string Joueur::getNom(){
    return nom;
}

void Joueur::setNom(string n){
    nom = n;
}

bool Joueur::ajouterTour(Tour* nouvelleTour)
{
	return tableauTour->ajouterTour(nouvelleTour);
}

bool Joueur::retirerTour(int index)
{
	return tableauTour->retirerTour(int index);
}


bool Joueur::reinitialiserTour()
{
		return tableauTour->reinitialiser();
}

int Joueur::getTaille()
{
	return tableauTour->getTaille();
}

Tour* Joueur::getTour(int index)
{
	return tableauTour->getTour(index);
}

