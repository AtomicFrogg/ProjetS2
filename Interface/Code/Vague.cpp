#include "../Header/Vague.h"

Vague::Vague(GUI* g):gui(g)
{
    g = new GUI();
}

Vague::~Vague()
{

}

void Vague::lancerVague() {
    int index = 40;
    if (FINJEU)
    {
        gui->getCarte()->debutEnnemie(index);
        gui->setFin(false);
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
            CLEAR = false;
            emit clearEnnemi();
            for (int index = 0; index < gui->getCarte()->getTailleEnnemie(); index++)
            {
                if (gui->getCarte()->getEnnemie()->getEnnemie(index)->deplacement())
                {
                    
                    gui->checkMove(index);
                    emit afficherEnnemi(index);
                }
            }
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
