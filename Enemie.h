#pragma once
#include "dimension.h"
//#include "Carte.h"

class Ennemie
{
	public:
		Ennemie(int v = 100, int vit = 1, int pos = 0, int r = 2);
		virtual ~Ennemie();
		int getVie();
		int getVitesse();
		int getPosition();
		void setVie(int v);
		virtual void setVitesse(int v) = 0;
		virtual void setPosition(int p) = 0;
		Dimension getCoordonnee();
		void setCoordonnee(Dimension coord);
		void setRevenu(int r);
		int getRevenu();

	private:
		int vie;
		int vitesse;
		int position;
		Dimension coordonnee;
		int revenu;
};

