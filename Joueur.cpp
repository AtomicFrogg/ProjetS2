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