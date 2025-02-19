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
	return tableauTour.ajouterTour(nouvelleTour);
}

bool Joueur::retirerTour(int index)
{
	return tableauTour.retirerTour(index);
}


bool Joueur::reinitialiser()
{
		return tableauTour.reinitialiser();
}

int Joueur::getTaille()
{
	return tableauTour.getTaille();
}

Tour* Joueur::getTour(int index)
{
	return tableauTour.getTour(index);
}

int Joueur::getPrix(int index)
{
	return tableauTour.getPrix(index);
}

void Joueur::setPrix(int index, int p)
{
	tableauTour.setPrix(index, p);
}

int Joueur::getTier(int index)
{
	return tableauTour.getTier(index);
}

void Joueur::setTier(int index, int t)
{
	tableauTour.setTier(index, t);
}

void Joueur::setVitesse(int index, int v)
{
	tableauTour.setVitesse(index, v);
}

int Joueur::getVitesse(int index)
{
	return tableauTour.getVitesse(index);
}

void Joueur::afficherTour(ostream& s)
{
	tableauTour.afficher(s);
}