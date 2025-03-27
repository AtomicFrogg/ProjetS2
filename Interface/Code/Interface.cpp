#include "../Header/Interface.h"

Interface::Interface(GUI *gui)
{
	layout = new QGridLayout;
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 0; j < LARGEUR; j++)
		{
			int type = gui->getDonnees(i, j)->type;
			Case *image = new Case(this,type);
			layout->addWidget(image,i,j);
		}
	}
	layout->setSpacing(0);
	this->setLayout(layout);
	
}

Interface::~Interface()
{
	delete layout;
}