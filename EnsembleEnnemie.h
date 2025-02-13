#ifndef ENSEMBLEENEMIE_H
#define ENSEMBLEENEMIE_H

#include <vector>
#include "Ennemie.h"

#ifndef BOOL
#define BOOL
const bool TRUE = 1;
const bool FALSE = 0;
#endif

class EnsembleEnnemie
{
	public:
		Dimension getPosition(int index);
		bool ajouterEnnemie(Ennemie* mob);
		bool retirerEnnemie(int index);
		void reinitialiser();
		int getTaille();
		void setCoordonnee(int index, Dimension coord);
		Dimension getCoordonnee(int index);
		int getPosition(int index);
		
		Ennemie* getEnnemie(int index);
	private:
		vector<Ennemie*> tableau;
};



#endif

