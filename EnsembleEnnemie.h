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
		bool ajouterEnnemie(Ennemie* mob);
		bool retirerEnnemie(int index);
		void reinitialiser();
		int getTaille();
		Ennemie* getEnnemie(int index);
	private:
		vector<Ennemie*> tableau;
};



#endif

