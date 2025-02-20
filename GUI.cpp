#include "GUI.h"

GUI::GUI()
{
    
};

GUI::~GUI()
{
    
};

Dimension GUI::getCoordonneeJoueur()
{
    return j->getPosition();
};

void GUI::moveJoueurUp(int y)
{
    int currX = getCoordonneeJoueur().x;
    int currY = getCoordonneeJoueur().y;
    int newY = currY + y;
    j->setPosition(currX, newY);
};

void GUI::moveJoueurDown(int y)
{
    int currX = getCoordonneeJoueur().x;
    int currY = getCoordonneeJoueur().y;
    int newY = currY + y;
    j->setPosition(currX, newY);
};

void GUI::moveJoueurDroite(int x)
{
    int currX = getCoordonneeJoueur().x;
    int currY = getCoordonneeJoueur().y;
    int newX = currX + x;
    j->setPosition(newX, currY);
};

void GUI::moveJoueurGauche(int x)
{
    int currX = getCoordonneeJoueur().x;
    int currY = getCoordonneeJoueur().y;
    int newX = currX + x;
    j->setPosition(newX, currY);
};

void GUI::draw(Dimension getCoordonneeJoueur(), const char joueur)
{
    
}

ostream& operator<<(ostream& os, const Joueur*);