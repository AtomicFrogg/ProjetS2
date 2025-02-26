#include "EnnemieBaltimore.h"

EnnemieBaltimore::EnnemieBaltimore(int v, int vit, int pos, int r)
{
	vie = v;
	vitesse = vit;
	position = pos;
	revenu = r;
}
int EnnemieBaltimore::getDegat() {
	return 5;
}
void EnnemieBaltimore::setPosition(int p) {
	if (p > 0) {
		position = p;
	}
}

void EnnemieBaltimore::setVitesse(int v)
{
	vitesse = v;
}
