#include "../Header/Vague.h"

Vague::Vague(GUI* g):gui(g)
{

}

Vague::~Vague()
{

}

void Vague::lancerVague() 
{
    int index;
    gui->vaguePlusUn();
    cout << gui->getVague();

    if (qte <= 0) index = 40;
    else index = qte;
    if (FINJEU)
    {
        FINJEU = false;
        qDebug() << "a";

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
        while (gui->getCarte()->getVie() > 0 && gui->getCarte()->getTailleEnnemie() > 0 && !FINJEU)
        {
            //cout << "MUON:" << qte;
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
            if (time < 1000)
            {
                Sleep(1000 - time);
            }
        }
        
    }
    FINJEU = true;
        //draw();
       /* cout << "Baleine :" << c->getCoordonnee(0).x;
        cout << "vie: " << c->getEnnemie()->getEnnemie(0)->getVie();*/
    
    emit finished();
}
