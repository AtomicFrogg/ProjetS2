#pragma once
#include <vector>
#include "Enemie.h"

#ifndef BOOL
#define BOOL
const bool TRUE = 1;
const bool FALSE = 0;
#endif
using namespace std;
class EnsembleEnemie
{
public:
	//Dimension getPosition(int index);
	void reinitialiser();
	int getTaille();
	void setCoordonnee(int index, Dimension coord);
	Dimension getCoordonnee(int index);
	int getPosition(int index);
	void setPosition(int index, int pos);
	bool ajouterEnnemie(Enemie* mob);
	bool retirerEnnemie(int index);
	Enemie* getEnnemie(int index);
private:
	vector<Enemie*> tableau;
};

