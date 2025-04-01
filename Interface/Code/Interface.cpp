#include "../Header/Interface.h"

Interface::Interface(GUI *gui)
{
	layout = new QGridLayout;
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 1; j < LARGEUR - 1; j++)
		{
			int type = gui->getDonnees(i, j)->type;
			Case *image = new Case(this, type, gui, i, j);
			layout->addWidget(image,i,j);
		}
	}
	layout->setContentsMargins(0,0,0,0);
	layout->setSpacing(0);
	this->setLayout(layout);
	
}

Interface::~Interface()
{
	delete layout;
}