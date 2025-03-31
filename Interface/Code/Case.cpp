#include "../Header/Case.h"

Case::Case(QWidget *parent, int type, GUI* gui, int x, int y):QLabel(parent)
{
	this->setFixedSize(CARRE, CARRE);

	switch (type)
	{

	case 0:
		this->setPixmap(QPixmap("Images/Grass.png").scaled(CARRE, CARRE));
		std::cout << "0";
		break;
	case 1:
		if (x == 0 || x == LARGEUR - 1)
		{

		}
        if (gui->getDonnees(y + 1, x)->type == 1 && gui->getDonnees(y - 1, x)->type == 1)
        {
			this->setPixmap(QPixmap("Images/Water2.png").scaled(CARRE, CARRE));
        }
        else if (gui->getDonnees(y,x + 1)->type == 1 && gui->getDonnees(y, x - 1)->type == 1)
        {
			this->setPixmap(QPixmap("Images/Water.png").scaled(CARRE, CARRE));
        }
        else if (gui->getDonnees(y, x - 1)->type == 1 && gui->getDonnees(y + 1, x)->type == 1)
        {
			this->setPixmap(QPixmap("Images/WaterCoin.png").scaled(CARRE, CARRE));
        }
        else if (gui->getDonnees(y, x + 1)->type == 1 && gui->getDonnees(y + 1, x)->type == 1)
        {
			this->setPixmap(QPixmap("Images/WaterCoin1.png").scaled(CARRE, CARRE));
        }
		else if (gui->getDonnees(y, x + 1)->type == 1 && gui->getDonnees(y - 1, x)->type == 1)
		{
			this->setPixmap(QPixmap("Images/WaterCoin2.png").scaled(CARRE, CARRE));
		}
		else if (gui->getDonnees(y, x - 1)->type == 1 && gui->getDonnees(y - 1, x)->type == 1)
		{
			this->setPixmap(QPixmap("Images/WaterCoin3.png").scaled(CARRE, CARRE));
		}

		std::cout << "1";
		break;
	default:
		
		break;
	}
}

Case::~Case()
{

}