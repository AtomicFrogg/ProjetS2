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

        void draw(Donnees tableauDonnees[HAUTEUR][LARGEUR], const char joueur);
        bool ajouterTourBase();
        bool ajouterTourSniper();
        bool ajouterTourCanonnier();
        bool ajouterTourNarvolt();
        bool retirerTour(int x, int y);
        Donnees* getDonneesJoueur();
        
    private:
        Donnees tableauDonnees[HAUTEUR][LARGEUR];
        Joueur* j;
        Carte* c;
};

