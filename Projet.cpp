// Projet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Enemie.h"
#include "Carte.h"

using namespace std;
int main()
{
    Enemie *enem = new Enemie();
    enem->setPosition(1);
    Enemie* enem2 = new Enemie();
    enem2->setPosition(3);
    Enemie* enem3 = new Enemie();
    enem3->setPosition(4);
    Enemie* enem4 = new Enemie();
    enem4->setPosition(5);
    Carte c;
    //ajouter un enemie
    c.getEnnemie()->ajouterEnnemie(enem);
    c.getEnnemie()->ajouterEnnemie(enem2);
    c.getEnnemie()->ajouterEnnemie(enem3);
    c.getEnnemie()->ajouterEnnemie(enem4);
    cout << "la position est: " << c.getEnnemie()->getPosition(0) << endl;
    cout << "la position est: " << c.getEnnemie()->getPosition(1) << endl;
    cout << "la position est: " << c.getEnnemie()->getPosition(2) << endl;
    cout << "la position est: " << c.getEnnemie()->getPosition(3) << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
