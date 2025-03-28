#pragma once
#include "Tour.h"
#include "Defenseur.h"

class Canonnier : public Tour
{
public:
	Canonnier(int d, float r, int x, int y, int va, int p, int t, Carte* c, float re);
	~Canonnier();
	void attaquer();
	bool ameliorerRange();
	bool ameliorerDegat();

private:
	float rangeExplosion;
};
