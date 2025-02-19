

#include <string.h>
#include "Defenseur.h"
#include "EnsembleTour.h"

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
		bool retirerTour(int index);
		bool reinitialiser();
		int getTaille();
		Tour* getTour(int index);
		void afficherTour(ostream& s);

		int getPrix(int index);
		void setPrix(int index, int p);
		int getTier(int index);
		void setTier(int index, int t);
		void setVitesse(int index, int v);
		int getVitesse(int index);
    	
};

#endif
