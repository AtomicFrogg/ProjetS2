#ifndef ENSEMBLEENEMIE_H
#define ENSEMBLEENEMIE_H

#include <vector>
#include "Ennemie.h"

const bool TRUE = 1;
const bool FALSE = 0;

class EnsembleEnnemie
{
	public:
		bool ajouterEnnemieFin(Ennemie* mob);
		bool retirerEnnemie(int index);
		void reinitialiser();
		int getTaille();
		Ennemie* getEnnemie(int index);
	private:
		vector<Ennemie*> tableau;
};



#endif

