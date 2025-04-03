#pragma once
#include <string.h>
#include "../../Tours/Header/Defenseur.h"
#include "../../Tours/Header/EnsembleTour.h"
#include "../../Tours/Header/TourBase1.h"
#include "../../Tours/Header/Canonnier.h"
#include "../../Tours/Header/Narvolt.h"
#include "DonneesTours.h"


class Joueur : public Defenseur {

private:
	string nom;
	EnsembleTour tableauTour;
	Carte* map;


public:
	Joueur(int d, float r, int x, int y, int va, Carte* c, string n);
	~Joueur();
	string getNom();
	void setNom(string n);

	Tour* ajouterTour(Tour* nouvelleTour);
	bool retirerTour(int index);
	Tour* ajouterTourBase();
	Tour* ajouterTourSniper();
	Tour* ajouterTourCanonnier();
	Tour* ajouterTourNarvolt();
	bool ameliorerRange(int index);
	bool ameliorerDegat(int index);


	bool reinitialiser();
	int getTaille();
	Tour* getTour(int index);
	void afficherTour(ostream& s);
	void attaquer();
	void attaquerJoueur();
	int getPrix(int index);
	void setPrix(int index, int p);
	int getTier(int index);
	void setTier(int index, int t);
	void setVitesse(int index, int v);
	int getVitesse(int index);

	DonneesTours DonneesNarvolt;
	DonneesTours DonneesCanonnier;
	DonneesTours DonneesSniper;
	DonneesTours DonneesTourBase;
};

