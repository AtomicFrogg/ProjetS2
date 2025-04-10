#pragma once
#include <ctime>
#include <Windows.h>
#include <iostream>
#include "Joueur.h"
#include "Carte.h"
#include "Donnees.h"
#include "DonneesEnnemies.h"
#include "DonneesTours.h"
#include "qmessagebox.h"

static bool FINJEU = true;


using namespace std;

class GUI
{

public:
    GUI();
    ~GUI();

    bool moveJoueurUp(int y);
    void moveJoueurDown(int y);
    void moveJoueurDroite(int x);
    void moveJoueurGauche(int x);
    Dimension getCoordonneeJoueur();

    //methodes relatives aux enemis
    void moveEnnemies();
    void attaqueEnnemie();
    void ajouterEnnemie(Ennemie* ptr);
    void retirerEnnemie(int index);

    //void draw();
    void drawControls();
    void drawInfoTour(int typeTour, int index);
    void chooseMap(int choixMap);
    bool ajouterTourBase();
    bool ajouterTourSniper();
    bool ajouterTourCanonnier();
    bool ajouterTourNarvolt();
    bool retirerTour();
    Donnees* getDonneesJoueur();
    bool ameliorerRange();
    bool ameliorerDegat();
    void setFin(bool etat);
    Donnees* getDonnees(int x, int y);
    Joueur* getJoueur();
    Carte* getCarte();
    int checkMove(int index);

    void setManette(bool estcemanette);
    bool getManette();
    void setNumCarte(int numero);
    int getNumCarte();
    bool lancer(int index);
    void affichageEnemie();
    int getVague();
    void vaguePlusUn();


   

private:
    Donnees tableauDonnees[HAUTEUR][LARGEUR];
    Carte* c;
    Joueur* j;
    bool manette;
    int numCarte;
    int vague;
};