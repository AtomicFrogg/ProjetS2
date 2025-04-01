#include "../Header/Interface.h"

Interface::Interface(GUI *gui)
{
	layout = new QGridLayout;
	this->setFixedSize(1000, HAUTEUR*30);
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 1; j < LARGEUR - 1; j++)
		{
			int type = gui->getDonnees(i, j)->type;

			Case *image = new Case(this,type,gui,i,j);
			QLabel *image = new QLabel(this);
			image->setFixedSize(30, 30);

			switch (type)
			{

			case 0:
				image->setPixmap(QPixmap("-1.png"));
				std::cout << "0";
				break;
			case 1:
				image->setPixmap(QPixmap("1.png"));
				std::cout << "1";
				break;
			case 2:
				image->setPixmap(QPixmap("1.png"));

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
			this->setLayout(layout);
		}
	}

	layout->setContentsMargins(0,0,0,0);
	layout->setSpacing(0);
	

	QPushButton *bouton = new QPushButton("Bouton");
	bouton->setCursor(Qt::PointingHandCursor);
	QObject::connect(bouton, SIGNAL(clicked()), qApp, SLOT(quit()));



	layout->addWidget(bouton, 0, LARGEUR);

	this->setLayout(layout);
	
}

Interface::~Interface()
{
	delete layout;
}

QGridLayout* Interface::getLayout()
{
	return layout;
}