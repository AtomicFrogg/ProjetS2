

#include <string.h>
#include "Defenseur.h"


#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur{

    private:
        string nom;
    public:
        Joueur();
        Joueur(string n = "joueur");
        ~Joueur();   
        string getNom();
        void setNom(string n);
};