#include "EnnemieBaleine.h"

EnnemieBaleine::EnnemieBaleine(int v, int vit, int pos, int r) 
{
	vie = v;
	vitesse = vit;
	position = pos;
	revenu = r;
}

int EnnemieBaleine::getDegat() {
	return 10;
}
void EnnemieBaleine::setPosition(int p) {
	if (p > 0) {
		position = p;
	}
}

void EnnemieBaleine::setVitesse(int v)
{
	vitesse = v;
}
