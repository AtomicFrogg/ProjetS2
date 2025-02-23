#ifndef ENSEMBLETOUR_H
#define ENSEMBLETOUR_H

#include "Tour.h"
#include <iostream>
#include <vector>



class EnsembleTour
{
	public:
		int ajouterTour(Tour* nouvelleTour);
		bool retirerTour(int index);
		bool reinitialiser();
		int getTaille();
	 	Tour* getTour(int index);
		void afficher(ostream &s);

		int getPrix(int index);
		void setPrix(int index,int p);
		int getTier(int index);
		void setTier(int index, int t);
		void setVitesse(int index, int v);
		int getVitesse(int index);
		void attaquer();
		virtual bool ameliorerRange(int index);
		virtual bool ameliorerDegat(int index);
	private:
		vector<Tour*> tableau;
};







#endif
