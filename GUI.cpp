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
    if (getDonneesJoueur()->type == 0)
    {
        getDonneesJoueur()->type = 2;
        getDonneesJoueur()->ptr = j->ajouterTourBase();
        getDonneesJoueur()->index = j->getTaille();
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourSniper()
{
    if (getDonneesJoueur()->type == 0)
    {
        getDonneesJoueur()->type = 3;
        getDonneesJoueur()->ptr = j->ajouterTourSniper();
        getDonneesJoueur()->index = j->getTaille();
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourCanonnier()
{
    if (getDonneesJoueur()->type == 0)
    {
        getDonneesJoueur()->type = 4;
        getDonneesJoueur()->ptr = j->ajouterTourCanonnier();
        getDonneesJoueur()->index = j->getTaille();
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourNarvolt()
{
    if (getDonneesJoueur()->type == 0)
    {
        getDonneesJoueur()->type = 5;
        getDonneesJoueur()->ptr = j->ajouterTourNarvolt();
        getDonneesJoueur()->index = j->getTaille();
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::retirerTour(int x, int y)
{
    int index = getDonneesJoueur()->index;
    if (getDonneesJoueur()->type >= 2)
    {
        if (j->retirerTour(index))
        {
            for (int i = 0; i < HAUTEUR; i++)
            {
                for (int j = 0; j < LARGEUR; j++)
                {
                    if (tableauDonnees[i][j].index >= index and tableauDonnees[i][j].type >= 2)
                    {
                        tableauDonnees[i][j].index = tableauDonnees[i][j].index - 1;
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
   
}


Donnees* GUI::getDonneesJoueur()
{
    return &tableauDonnees[getCoordonneeJoueur().y][getCoordonneeJoueur().x];
}