#include "Joueur.h"


Joueur::Joueur(){
    nom = "Jacob";
}

Joueur::Joueur(string n){
    setNom(n);
}

Joueur::~Joueur(){
    nom = null;
}

string Joueur::getNom(){
    return nom;
}

void Joueur::setNom(string n){
    nom = n;
}

bool Joueur::ajouterEnnemie(Ennemie* ptr)
{
	if(ptr == nullptr) return FALSE;
	tableauEnnemie.ajouterEnnemie(ptr);
	return TRUE;
}

bool Joueur::retirerEnnemie(int index)
{
	if(index < this->tableauEnnemie.getTaille() and index > 0)
	{
		tableauEnnemie.retirerEnnemie(index);
		
	}
}

EnsembleEnnemie* Joueur::getEnnemieTaille()
{
	return &tableauEnnemie;
}

