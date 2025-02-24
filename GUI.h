#include <iostream>
#include "Joueur.h"
#include "Carte.h"
#include "Donnees.h"

using namespace std;

class GUI
{
    public:
        GUI();
        ~GUI();
    
        void moveJoueurUp(int y);
        void moveJoueurDown(int y);
        void moveJoueurDroite(int x);
        void moveJoueurGauche(int x);
        Dimension getCoordonneeJoueur();

        void draw();
        bool ajouterTourBase();
        bool ajouterTourSniper();
        bool ajouterTourCanonnier();
        bool ajouterTourNarvolt();
        bool retirerTour();
        Donnees* getDonneesJoueur();
        bool ameliorerRange();
        bool ameliorerDegat();

        Joueur* getJoueur();
        Carte* getCarte();
        
    private:
        Donnees tableauDonnees[HAUTEUR][LARGEUR];
        Carte *c;
        Joueur *j;
        
};

