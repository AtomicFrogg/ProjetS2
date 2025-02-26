#pragma once
#include "Ennemie.h"
class EnnemieBaltimore : public Ennemie
{
public:
	int getDegat();
	EnnemieBaltimore(int v = 50, int vit = 1, int pos = 5, int r = 2);
	void setVitesse(int v);
	void setPosition(int p);
};



