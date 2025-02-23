#include "GUI.h"

GUI::GUI()
{
    for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {
            tableauDonnees[i][j].type = 0;
            tableauDonnees[i][j].ptr = nullptr;
            tableauDonnees[i][j].index = -1;
        }
    }

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


bool GUI::ajouterTourBase()
{
    if (tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].type == 0)
    {
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].type = 2;
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].ptr = j->ajouterTourBase();
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].index = j->getTaille();
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourSniper()
{
    if (tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].type == 0)
    {
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].type = 3;
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].ptr = j->ajouterTourSniper();
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].index = j->getTaille();
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourCanonnier()
{
    if (tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].type == 0)
    {
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].type = 4;
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].ptr = j->ajouterTourCanonnier();
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].index = j->getTaille();
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourNarvolt()
{
    if (tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].type == 0)
    {
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].type = 5;
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].ptr = j->ajouterTourNarvolt();
        tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x].index = j->getTaille();
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::retirerTour(int x, int y)
{

}
