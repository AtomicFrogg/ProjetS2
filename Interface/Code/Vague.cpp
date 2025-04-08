#include "Vague.h"

Vague::Vague(GUI* g)
{

}

Vague::~Vague()
{

}

bool Vague::lancerVague() {
    int index = 40;
    if (!FINJEU)
    {
        return false;
    }
    else
    {
        g->setFin(false);
        g->getCarte()->debutEnnemie(index);
        Dimension coord;
        coord.x = 0;
        coord.y = 9;
        for (int i = 0; i < g->getCarte()->getTailleEnnemie(); i++)
        {
            g->getCarte()->getEnnemie()->getEnnemie(i)->setCoordonnee(coord);
        }
        clock_t start;
        while (g->getCarte()->getVie() > 0 && g->getCarte()->getTailleEnnemie() > 0 && FINJEU)
        {
            start = clock();
            emit afficherEnnemi();
            g->moveEnnemies();
            g->getJoueur()->attaquer();
            int time = clock() - start;
            if (time < 700)
            {
                Sleep(700 - time);
            }
        }
        g->setFin(true);
        return true;
        //draw();
       /* cout << "Baleine :" << c->getCoordonnee(0).x;
        cout << "vie: " << c->getEnnemie()->getEnnemie(0)->getVie();*/
    }
    return true;
}
