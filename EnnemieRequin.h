#pragma once
#include "Ennemie.h"
class EnnemieRequin :public Ennemie
{
public:
	int getDegat();
	EnnemieRequin(int v = 150, int vit = 12, int pos = 5, int r = 2);
	void setVitesse(int v);
	void setPosition(int p);
};


