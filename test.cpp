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
	Carte* map = new Carte(100,2000);
	cout<< "Tourbase1" <<endl;
	Tour* TestTour = new TourBase1(2,5,3,0,0,300,1,map);
	TestTour->afficher(cout);
	TestTour->ameliorerDegat();
	TestTour->afficher(cout);
	cout << map->getArgent() << endl;
	TestTour->ameliorerDegat();
	TestTour->afficher(cout);
	cout << map->getArgent() << endl;
	TestTour->ameliorerDegat();
	TestTour->afficher(cout);
	cout << map->getArgent() << endl;

	delete map, TestTour;
}

void Test::testEnnemie()
{

}

void Test::testEnsembleEnnemie()
{

}

void Test::testEnsembleTour()
{
	EnsembleTour TestVecteur;
	Carte* map = new Carte(100, 2000);
	cout << "EnsembleTour" << endl;
	Tour* TestTour = new TourBase1(1, 1, 1, 0, 0, 300, 1, map);
	Tour* TestTour1 = new TourBase1(2, 5, 3, 0, 0, 300, 1, map);
	Tour* TestTour2 = new TourBase1(2, 2, 2, 0, 0, 300, 1, map);
	TestVecteur.ajouterTour(TestTour);
	TestVecteur.ajouterTour(TestTour1);
	TestVecteur.ajouterTour(TestTour2);
	TestVecteur.afficher(cout);
	cout << TestVecteur.getTaille() << endl;
	TestVecteur.getTour(1)->setDegat(12);
	TestVecteur.retirerTour(0);
	TestVecteur.afficher(cout);
	cout << TestVecteur.getTaille() << endl;
	TestVecteur.reinitialiser();
	TestVecteur.afficher(cout);
	cout << TestVecteur.getTaille()<<endl;
}

void Test::testCarte()
{

}
