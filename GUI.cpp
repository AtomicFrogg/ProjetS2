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
    if(y < HAUTEUR and y >= 0)
    {
        int currX = getCoordonneeJoueur().x;
        int currY = getCoordonneeJoueur().y;
        int newY = currY + y;
        j->setPosition(currX, newY);
    }
};

void GUI::moveJoueurDown(int y)
{
    if (y < HAUTEUR and y >= 0)
    {
        int currX = getCoordonneeJoueur().x;
        int currY = getCoordonneeJoueur().y;
        int newY = currY - y;
        j->setPosition(currX, newY);
    }
};

void GUI::moveJoueurDroite(int x)
{
    if (x < LARGEUR and x >= 0)
    {
        int currX = getCoordonneeJoueur().x;
        int currY = getCoordonneeJoueur().y;
        int newX = currX + x;
        j->setPosition(newX, currY);
    }
};

void GUI::moveJoueurGauche(int x)
{
    if (x < LARGEUR and x >= 0)
    {
        int currX = getCoordonneeJoueur().x;
        int currY = getCoordonneeJoueur().y;
        int newX = currX - x;
        j->setPosition(newX, currY);
    }
};

void GUI::draw(Dimension getCoordonneeJoueur(), const char joueur)
{
    
}

ostream& operator<<(ostream& os, const Joueur*);