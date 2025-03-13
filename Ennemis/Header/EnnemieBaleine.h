#pragma once
#include "Ennemie.h"
class EnnemieBaleine :public Ennemie
{
public:
	int getDegat();
	EnnemieBaleine(int v = 50, int vit = 1, int pos = 5, int r = 2);
	void setVitesse(int v);
	void setPosition(int p);
};



