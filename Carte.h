#ifndef CARTE_H
#define CARTE_H


const int hauteur = 15;
const int largeur = 30;


class Carte
{
	public:
		bool ajouterTour(Tour* ptr);
		bool vendreTour(int index);
		
		bool ajouterEnnemie(Ennemie* ptr);
		bool lancerVague(int index);
		
		int getVie();
		int getArgent();
		void setVie(int v);
		void setArgent(int a);
		
	private:
		int map[hauteur][largeur];
		int vie;
		int argent;
		EnsembleTour tableauTour;
		EnsembleEnnemie tableauEnnemie;
};







#endif
