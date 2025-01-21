#ifndef ENSEMBLETOUR_H
#define ENSEMBLETOUR_H

#include "Tour.h"
#include <vector>

#ifndef BOOL
#define BOOL
const bool TRUE = 1;
const bool FALSE = 0;
#endif

class EnsembleTour
{
	public:
		bool ajouterTour(Tour* nouvelleTour);
		int retirerTour(int index);
		bool reinitialiser();
		int getTaille();
	 	Tour* getTour(int index);

	private:
		vector<Tour*> tableau;
};







#endif
