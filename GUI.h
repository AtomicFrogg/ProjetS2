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

    void draw(Dimension getCoordonneeJoueur(), const char joueur);

    private:
    Joueur* j;
    Carte* c;
};