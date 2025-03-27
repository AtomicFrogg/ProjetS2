#include "../Header/Interface.h"

Interface::Interface(GUI *gui)
{
	layout = new QGridLayout;
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 0; j < LARGEUR; j++)
		{
			int type = gui->getDonnees(i, j)->type;
			QLabel *image = new QLabel(this);
			image->setFixedSize(30, 30);

			switch (type)
			{

			case 0:
				image->setPixmap(QPixmap("-1.png"));
				std::cout << "0";
				break;
			case 1:
				image->setPixmap(QPixmap("../../Images/1.png"));
				std::cout << "1";
				break;
			case 2:
				image->setPixmap(QPixmap("Image.png"));

				break;
			case 3:
				image->setPixmap(QPixmap("Image.png"));

				break;
			case 4:
				image->setPixmap(QPixmap("Image.png"));

				break;
			case 5:
				image->setPixmap(QPixmap("Image.png"));

				break;
			default:

				break;
			}
			layout->addWidget(image,i,j);
		}
	}

}

Interface::~Interface()
{
	delete layout;
}