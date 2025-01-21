#ifndef ENNEMIE_H
#define ENNEMIE_H

#include "dimension.h"
using namespace std;



class Ennemie{
	public:
		Ennemie(int v = 100, int vit = 1, int pos = 0);
		virtual ~Ennemie();
		int getVie();
		int getVitesse();
		int getPosition();
		void setVie(int v);
		virtual void setVitesse(int v) = 0;
		virtual void setPosition(int p) = 0;
		void setCoordonnee(Dimension coord);
		
	private:
		int vie;
		int vitesse;
		int position;
		Dimension coordonnee;
};






#endif
