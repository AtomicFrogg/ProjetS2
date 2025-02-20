#include <iostream>
#include "Joueur.h"
#include "Carte.h"

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

<<<<<<< HEAD
    void draw(Dimension getCoordonneeJoueur(), const char joueur);
=======
    void draw(const Dimension& coordonneeJoueur, const char joueur);
>>>>>>> origin/main

    private:
    Joueur* j;
    Carte* c;
};