#pragma once
#include <ctime>
#include <Windows.h>
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

    //methodes relatives aux enemis
    void moveEnnemies();
    void lancerVague(int index);
    void attaqueEnnemie();
    void ajouterEnnemie(Ennemie* ptr);
    void retirerEnnemie(int index);

    void draw();
    void drawInfoTour(int typeTour, Defenseur* ptr);
    void chooseMap(int choixMap);
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
    int checkMove(int index);


private:
    Donnees tableauDonnees[HAUTEUR][LARGEUR];
    Carte* c;
    Joueur* j;

};