#include "Vague.h"

bool Vague::lancerVague() {
    cout << "Je me suis rendu a lancer vague";
    int index = 40;
    if (!FINJEU)
    {
        std::cout << "oops FINJEU est false";
        return false;
    }
    else
    {
        std::cout << "on est dans le else de lancer vague";
        g->getCarte()->debutEnnemie(index);
        Dimension coord;
        coord.x = 0;
        coord.y = 9;
        //std::cout << "un" << endl;
        for (int i = 0; i < g->getCarte()->getTailleEnnemie(); i++)
        {
            g->getCarte()->getEnnemie()->getEnnemie(i)->setCoordonnee(coord);
            //std::cout << "deux" << endl;
        }
        clock_t start;
        //std::cout << "trois" << endl;
        while (g->getCarte()->getVie() > 0 && g->getCarte()->getTailleEnnemie() > 0 && FINJEU)
        {
            //std::cout << "quatre" << endl;
            start = clock();
            afficherEnnemi();
            g->moveEnnemies();
            g->getJoueur()->attaquer();
            int time = clock() - start;
            //std::cout << "cinq" << endl;
            if (time < 700)
            {
                Sleep(700 - time);
            }
        }
        g->setFin(true);
        //std::cout << "six" << endl;
        return true;
        //draw();
       /* cout << "Baleine :" << c->getCoordonnee(0).x;
        cout << "vie: " << c->getEnnemie()->getEnnemie(0)->getVie();*/
    }
    return true;
}
