

#include <string.h>
#include "Defenseur.h"
#include "EnsembleEnnemie.h"

#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur{

    private:
        string nom;
		EnsembleTour tableauTour;
    public:
        Joueur();
        Joueur(string n = "joueur");
        ~Joueur();   
        string getNom();
        void setNom(string n);
        
		bool ajouterTour(Tour* nouvelleTour);
		int retirerTour(int index);
		bool reinitialiserTour();
		int getTaille();
	 	Tour* getTour(int index);
	

    	
};

#endif
