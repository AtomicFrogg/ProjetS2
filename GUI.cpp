#include "GUI.h"

GUI::GUI()
{
    c = new Carte(100, 10000);
    j = new Joueur(5, 1.5, 0, 0, 4, c, "Jacob");
    for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {
            tableauDonnees[i][j].type = 0;
            tableauDonnees[i][j].ptr = nullptr;
            tableauDonnees[i][j].index = -1;
        }
    }
}

GUI::~GUI()
{
    delete c;
    delete j;
};
//Definition des methodes pour les classes enemies

void GUI::moveEnemies() {
    for (int index = 0; index < c->getTailleEnnemie(); index++)
    {
      if (c->getEnnemie()->getEnnemie(index)->deplacement())
        {
            int move = checkMove(index);
            if (move >= 1 and move <= 4)
            {
                c->getEnnemie()->getEnnemie(index)->setCoordonnee();
            }
            
        }
    }
  
}

void GUI::lancerVague(int index) {
    while (c->getVie() > 0 and c->getTailleEnnemie() > 0 and )
    {
        moveEnemies();
        j->attaquer();
    }
}

void GUI::attaqueEnemie() {
    c->attaqueEnemie();
}

void GUI::ajouterEnemie(Ennemie* ptr) {
    c->ajouterEnnemie(ptr);
}

void GUI::retirerEnemie(int index) {
    c->retirerEnnemie(index);
}

Dimension GUI::getCoordonneeJoueur()
{
    return j->getPosition();
};

void GUI::moveJoueurUp(int y)
{
    if (getCoordonneeJoueur().y + 1 < HAUTEUR && getCoordonneeJoueur().y >= 0)
    {
        int currX = getCoordonneeJoueur().x;
        int currY = getCoordonneeJoueur().y;
        int newY = currY + y;
        j->setPosition(currX, newY);
    }
};

void GUI::moveJoueurDown(int y)
{
    if (getCoordonneeJoueur().y < HAUTEUR && getCoordonneeJoueur().y > 0)
    {
        int currX = getCoordonneeJoueur().x;
        int currY = getCoordonneeJoueur().y;
        int newY = currY - y;
        j->setPosition(currX, newY);
    }
};
void GUI::moveJoueurDroite(int x)
{
    if (getCoordonneeJoueur().x + 1 < LARGEUR && getCoordonneeJoueur().x >= 0)
    {
        int currX = getCoordonneeJoueur().x;
        int currY = getCoordonneeJoueur().y;
        int newX = currX + x;
        j->setPosition(newX, currY);
    }
};

void GUI::moveJoueurGauche(int x)
{
    if (getCoordonneeJoueur().x < LARGEUR && getCoordonneeJoueur().x > 0)
    {
        int currX = getCoordonneeJoueur().x;
        int currY = getCoordonneeJoueur().y;
        int newX = currX - x;
        j->setPosition(newX, currY);
    }
};

void GUI::draw()
{
    int m, n;
    for (int i = 0; i < 30; i++)
    {
        cout << endl;
    }
    cout << "Argent: " << c->getArgent() << endl;
    cout << "Vie: " << c->getVie() << endl;
    for (m = HAUTEUR - 1; m >= 0; m--)
    {
        cout << endl;

        for (n = 0; n < LARGEUR; n++)
        {
            if (getCoordonneeJoueur().x == n && getCoordonneeJoueur().y == m)
            {
                cout << "j";
                if (tableauDonnees[m][n].type != 0 && tableauDonnees[m][n].type != 1)
                {
                    drawInfoTour();
                }
            }

            //if(n == 0 || n == 29)
            //{
            //    cout << "|\n|";
            //}

            else if (tableauDonnees[m][n].type == 1)
            {
                cout << "1";
            }
            else if (tableauDonnees[m][n].type == 2)
            {
                cout << "2";
            }
            else if (tableauDonnees[m][n].type == 3)
            {
                cout << "3";
            }
            else if (tableauDonnees[m][n].type == 4)
            {
                cout << "4";
            }
            else if (tableauDonnees[m][n].type == 5)
            {
                cout << "5";

            }
            else if (m == 0 || m == HAUTEUR - 1)
            {
                cout << "_";
            }
            else if ((n == 0 || n == LARGEUR - 1) && tableauDonnees[m][n].type == 0 && m != 0 && m != HAUTEUR - 1)
            {
                cout << "|";
            }
            else if (tableauDonnees[m][n].type == 0)
            {
                cout << " ";
            }
        }
    }
}




bool GUI::ajouterTourBase()
{
    if (getDonneesJoueur()->type == 0 && c->getArgent() >= 400)
    {
        c->setArgent(c->getArgent() - 400);
        getDonneesJoueur()->type = 2;
        getDonneesJoueur()->ptr = j->ajouterTourBase();
        getDonneesJoueur()->index = j->getTaille() - 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourSniper()
{
    if (getDonneesJoueur()->type == 0 && c->getArgent() >= 1200)
    {
        c->setArgent(c->getArgent() - 1200);
        getDonneesJoueur()->type = 3;
        getDonneesJoueur()->ptr = j->ajouterTourSniper();
        getDonneesJoueur()->index = j->getTaille() - 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourCanonnier()
{
    if (getDonneesJoueur()->type == 0 && c->getArgent() >= 800)
    {
        c->setArgent(c->getArgent() - 800);
        getDonneesJoueur()->type = 4;
        getDonneesJoueur()->ptr = j->ajouterTourCanonnier();
        getDonneesJoueur()->index = j->getTaille() - 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::ajouterTourNarvolt()
{
    if (getDonneesJoueur()->type == 0 && c->getArgent() >= 600)
    {
        c->setArgent(c->getArgent() - 600);
        getDonneesJoueur()->type = 5;
        getDonneesJoueur()->ptr = j->ajouterTourNarvolt();
        getDonneesJoueur()->index = j->getTaille() - 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool GUI::retirerTour()
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
                    if (tableauDonnees[i][j].index >= index && tableauDonnees[i][j].type >= 2)
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

Carte* GUI::getCarte()
{
    return c;
}

Joueur* GUI::getJoueur()
{
    return j;
}

bool GUI::ameliorerRange()
{
    bool reussite = j->ameliorerRange(getDonneesJoueur()->index);
    if (reussite == false)
    {
        cout << "Argent trop faible ou deja top tier";
        return 0;
    }
    return 1;
}

bool GUI::ameliorerDegat()
{
    bool reussite = j->ameliorerDegat(getDonneesJoueur()->index);
    if (reussite == false)
    {
        cout << "Argent trop faible ou deja top tier";
        return 0;
    }
    return 1;
}

void GUI::chooseMap(int choixMap)
{
    int m, n;
    if (choixMap == 1)
    {
        m = 9;
        for (n = 1; n <= 5; n++)
        {
            tableauDonnees[m][n].type = 1;
        }
        tableauDonnees[8][5].type = 1;
        m = 7;
        for (n = 5; n <= 12; n++)
        {
            tableauDonnees[m][n].type = 1;
        }
        tableauDonnees[8][12].type = 1;
        tableauDonnees[9][12].type = 1;
        m = 10;
        for (n = 12; n <= 17; n++)
        {
            tableauDonnees[m][n].type = 1;
        }
        n = 17;
        for (m = 10; m >= 4; m--)
        {
            tableauDonnees[m][n].type = 1;
        }
        m = 4;
        for (n = 17; n <= 23; n++)
        {
            tableauDonnees[m][n].type = 1;
        }
        tableauDonnees[5][23].type = 1;
        tableauDonnees[6][23].type = 1;
        tableauDonnees[6][24].type = 1;
        tableauDonnees[6][25].type = 1;
        tableauDonnees[7][25].type = 1;
        tableauDonnees[7][26].type = 1;
        tableauDonnees[8][26].type = 1;
        tableauDonnees[8][27].type = 1;
        tableauDonnees[8][28].type = 1;
    }
}

void GUI::drawInfoTour()
{
    //do later
}

int GUI::checkMove(int index)
{
    int pos = c->getEnnemie()->getEnnemie(index)->getPosition();
    Dimension newPos;
    if (pos != 1)
    {
        if (tableauDonnees[c->getCoordonnee(index).y + 1][c->getCoordonnee(index).x].type == 1) 
        {
            c->getEnnemie()->getEnnemie(index)->setPosition(2);
            newPos.x = c->getCoordonnee(index).x;
            newPos.y = c->getCoordonnee(index).y + 1;
            c->getEnnemie()->getEnnemie(index)->setCoordonnee(newPos);
            return 1;
        }
    }
    if (pos != 2)
    {
        if (tableauDonnees[c->getCoordonnee(index).y - 1][c->getCoordonnee(index).x].type == 1) 
        {
            c->getEnnemie()->getEnnemie(index)->setPosition(1);
            newPos.x = c->getCoordonnee(index).x;
            newPos.y = c->getCoordonnee(index).y - 1;
            c->getEnnemie()->getEnnemie(index)->setCoordonnee(newPos);
            return 2;
        }
    }
    if (pos != 3)
    {
        if (tableauDonnees[c->getCoordonnee(index).y][c->getCoordonnee(index).x + 1].type == 1) 
        {
            c->getEnnemie()->getEnnemie(index)->setPosition(4);
            newPos.x = c->getCoordonnee(index).x + 1;
            newPos.y = c->getCoordonnee(index).y;
            c->getEnnemie()->getEnnemie(index)->setCoordonnee(newPos);
            return 3;
        }
    }
    if (pos != 4)
    {
        if (tableauDonnees[c->getCoordonnee(index).y][c->getCoordonnee(index).x - 1].type == 1)
        {
            c->getEnnemie()->getEnnemie(index)->setPosition(3);
            newPos.x = c->getCoordonnee(index).x - 1;
            newPos.y = c->getCoordonnee(index).y;
            c->getEnnemie()->getEnnemie(index)->setCoordonnee(newPos);
            return 4;
        }
    }
    return -1;
}