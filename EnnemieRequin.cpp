#include "EnnemieRequin.h"

EnnemieRequin::EnnemieRequin(int v, int vit, int pos, int r)
{
	vie = v;
	vitesse = vit;
	position = pos;
	revenu = r;
}

int EnnemieRequin::getDegat() {
	return 6;
}
void EnnemieRequin::setPosition(int p) {
	if (p > 0) {
		position = p;
	}
}

void EnnemieRequin::setVitesse(int v)
{
	vitesse = v;
}

