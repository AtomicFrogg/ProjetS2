#pragma once
#include <vector>
#include "qmutex.h"
#include "Ennemie.h"


using namespace std;
class EnsembleEnnemie
{
public:
	//Dimension getPosition(int index);
	void reinitialiser();
	int getTaille();
	void setCoordonnee(int index, Dimension coord);
	Dimension getCoordonnee(int index);
	void moveEnnemie(int x, int y);
	void deplacementEnnemie();
	int getPosition(int index);
	void setPosition(int index, int pos);
	bool ajouterEnnemie(Ennemie* mob);
	bool retirerEnnemie(int index);
	Ennemie* getEnnemie(int index);
private:
	vector<Ennemie*> tableau;
};


