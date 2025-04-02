#include "../Header/Interface.h"

Interface::Interface(GUI *gui)
{
	Case* image;
	layout = new QGridLayout;
	this->setFixedSize(1000, HAUTEUR*30);
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 1; j < LARGEUR - 2; j++)
		{
			int type = gui->getDonnees(i, j)->type;

			image = new Case(this,type,gui,i,j);
			image->setFixedSize(30, 30);

			
			layout->addWidget(image,i,j);
			
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