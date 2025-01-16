#ifndef ENSEMBLETOUR_H
#define ENSEMBLETOUR_H


class EnsembleTour
{
	public:
		bool ajouterTour(Tour* nouvelleTour);
		bool retirerTour(int index);
		bool reinitialiser();
		int getTaille();
	 	Tour* getTour(int index);

	private:
		Vector<Tour*> tableau;
}







#endif
