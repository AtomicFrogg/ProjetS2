#include "../Header/Case.h"

Case::Case(QWidget *parent, int type):QLabel(parent)
{
	this->setFixedSize(CARRE, CARRE);

	switch (type)
	{

	case 0:
		this->setPixmap(QPixmap("Images/0.png").scaled(CARRE,CARRE));
		std::cout << "0";
		break;
	case 1:
		this->setPixmap(QPixmap("Images/1.png"));
		std::cout << "1";
		break;
	case 2:
		this->setPixmap(QPixmap("Image.png"));

		break;
	case 3:
		this->setPixmap(QPixmap("Image.png"));

		break;
	case 4:
		this->setPixmap(QPixmap("Image.png"));

		break;
	case 5:
		this->setPixmap(QPixmap("Image.png"));

		break;
	default:
		
		break;
	}
}

Case::~Case()
{

}