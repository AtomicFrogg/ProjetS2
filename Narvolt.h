#pragma once

#include "Tour.h"
#include "Defenseur.h"

class Narvolt : public Tour
{
public:
	Narvolt(int d, float r, int x, int y, int va, int p, int t, Carte* c, int rb, float re);
	~Narvolt();
	void attaquer();
	bool ameliorerRange();
	bool ameliorerDegat();

private:
	int rebond;
	float rangeElectricte;
};
