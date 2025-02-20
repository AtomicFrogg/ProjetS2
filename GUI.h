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
    int getInput();

    void draw(const Dimension& coordonneeJoueur, const char joueur);
};

ostream& operator<<(ostream& os, const )