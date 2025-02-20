#pragma once

#include "Tour.h"
#include "Defenseur.h"

class Narvolt : public Tour
{
public:
	Narvolt(int v, int d, float r, int x, int y, int p, int t, Carte* c);
	­~Narvolt();
	void attaquer();
	bool ameliorerRange();
	bool ameliorerDegat();

private:
	int rebond;
	float rangeElectricte;
};
