#include <iostream>
#include "Joueur.h"
#include "Carte.h"
#include "Données.h"

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

        void draw(Dimension getCoordonneeJoueur(), const char joueur);
        bool ajouterTourBase();
        bool ajouterTourSniper();
        bool ajouterTourCanonnier();
        bool ajouterTourNarvolt();
        bool retirerTour(int index);

        
    private:
        Donnees tableauDonnees[HAUTEUR][LARGEUR];
        Joueur* j;
        Carte* c;
};

