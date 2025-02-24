#pragma once
#include <vector>
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
	int getPosition(int index);
	void setPosition(int index, int pos);
	bool ajouterEnnemie(Ennemie* mob);
	bool retirerEnnemie(int index);
	Ennemie* getEnnemie(int index);
	int getVie(int index);
private:
	vector<Ennemie*> tableau;
};

