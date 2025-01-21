#ifndef ENSEMBLETOUR_H
#define ENSEMBLETOUR_H

#include <vector>

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
