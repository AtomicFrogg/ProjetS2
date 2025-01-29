

#include <string.h>
#include "Defenseur.h"
#include "EnsembleEnnemie.h"

#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur{

    private:
        string nom;
        EnsembleEnnemie tableauEnnemie;
    public:
        Joueur();
        Joueur(string n = "joueur");
        ~Joueur();   
        string getNom();
        void setNom(string n);
        
    	EnsembleEnnemie* getEnnemie();
        bool ajouterEnnemie(Ennemie* ptr);
		bool retirerEnnemie(int index);
};