#include "test.h"

void Test::testTour()
{
//mettre la fonction attaquer de tour en commentaire pour essayer;
/*
	cout << "Tour de base" << endl;
	Tour TestTour;
	TestTour.afficher(cout);
	
	TestTour.setPosition(3,4);
	TestTour.setRange(5);
	TestTour.setPrix(300);
	TestTour.setTier(3);
	TestTour.afficher(cout);
	
	Tour TestTour1(3,12,4,200,4);
	TestTour1.afficher(cout);
*/
	Carte map; 
	cout<< "Tourbase1" <<endl;
	Tour* TestTour = new TourBase1(2,5,3,0,0,300,1,&map);
	TestTour->afficher(cout);
	TestTour->ameliorerRange();
	TestTour->afficher(cout);
	TestTour->ameliorerDegat();
	TestTour->afficher(cout);
}

void Test::testEnnemie()
{

}

void Test::testEnsembleEnnemie()
{

}

void Test::testEnsembleTour()
{

}

void Test::testCarte()
{

}
