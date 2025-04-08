#include "../Header/Vague.h"

Vague::Vague(GUI* g):gui(g)
{

}

Vague::~Vague()
{

}

void Vague::lancerVague() {
    int index = 40;
    if (FINJEU)
    {
        qDebug() << "a";
        gui->setFin(false);
        qDebug() << "b";
        gui->getCarte()->debutEnnemie(index);
        qDebug() << "c";
        Dimension coord;
        coord.x = 0;
        coord.y = 9;
        for (int i = 0; i < gui->getCarte()->getTailleEnnemie(); i++)
        {
            gui->getCarte()->getEnnemie()->getEnnemie(i)->setCoordonnee(coord);
        }
        clock_t start;
        while (gui->getCarte()->getVie() > 0 && gui->getCarte()->getTailleEnnemie() > 0 && FINJEU)
        {
            start = clock();
            emit afficherEnnemi();
            gui->moveEnnemies();
            gui->getJoueur()->attaquer();
            emit updateStatus();
            int time = clock() - start;
            if (time < 700)
            {
                Sleep(700 - time);
            }
        }
        gui->setFin(true);
        //draw();
       /* cout << "Baleine :" << c->getCoordonnee(0).x;
        cout << "vie: " << c->getEnnemie()->getEnnemie(0)->getVie();*/
    }
    emit finished();
}
