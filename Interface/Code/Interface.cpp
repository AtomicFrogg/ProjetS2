#include "../Header/Interface.h"

Interface::Interface(GUI *gui)
{
	g = gui;
	Case* image;
	layout = new QGridLayout;
	Hbox = new QHBoxLayout;
	VboxBoutton = new QVBoxLayout;

	this->setFixedHeight(590);

	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 1; j < LARGEUR - 1; j++)
		{
			int type = gui->getDonnees(i, j)->type;

			image = new Case(this,type,gui,i,j);
			//image->setFixedSize(30, 30);


			string nom = "Case";
			nom += std::to_string(i);
			nom.append(";");	
			nom += std::to_string(j);

			grille[nom] = image;
			layout->addWidget(image,i,j);
		}
	}
	
	layout->setContentsMargins(0,0,0,0);
	layout->setSpacing(0);

	Hbox->setContentsMargins(0, 0, 0, 0);
	int sizeX = 150;
	int sizeY = 120;
	QPushButton* TB = new QPushButton("Tour de Base");
	TB->setCursor(Qt::PointingHandCursor);
	TB->setFixedSize(sizeX,sizeY);
	QObject::connect(TB, SIGNAL(clicked()), this, SLOT(ajouterTourBase()));
	VboxBoutton->addWidget(TB, 0);

	QPushButton *Canon = new QPushButton("Canonnier");
	Canon->setCursor(Qt::PointingHandCursor);
	Canon->setFixedSize(sizeX,sizeY);
	QObject::connect(Canon, SIGNAL(clicked()), this, SLOT(ajouterCanonnier()));
	VboxBoutton->addWidget(Canon, 1);

	QPushButton* Narv = new QPushButton("Narvolt");
	Narv->setFixedSize(sizeX, sizeY);
	Narv->setCursor(Qt::PointingHandCursor);
	QObject::connect(Narv, SIGNAL(clicked()), this, SLOT(ajouterNarvolt()));
	VboxBoutton->addWidget(Narv, 2);

	QPushButton* Sni = new QPushButton("Sniper");
	Sni->setFixedSize(sizeX, sizeY);
	Sni->setCursor(Qt::PointingHandCursor);
	QObject::connect(Sni, SIGNAL(clicked()), this, SLOT(ajouterSniper()));
	VboxBoutton->addWidget(Sni, 3);

	

	QPushButton* quit = new QPushButton("QUITTER");
	quit->setCursor(Qt::PointingHandCursor);
	quit->setFixedSize(sizeX, sizeY-50);
	QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	VboxBoutton->addWidget(quit, 7);

	Hbox->addLayout(layout, 0);
	Hbox->addLayout(VboxBoutton, 1);
	this->setLayout(Hbox);

}

Interface::~Interface()
{
	delete layout;
}

QGridLayout* Interface::getLayout()
{
	return layout;
}

Case* Interface::getCase(int i, int j)
{
	string nom = "Case";
	nom += std::to_string(i);
	nom.append(";");
	nom += std::to_string(j);
	Case* lay = grille[nom];
	return grille[nom];
}

bool Interface::ajouterNarvolt() {
	int i = HAUTEUR - g->getCoordonneeJoueur().y;
	int j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterNarvolt();
	grille->show();

	

	return true;
}

bool Interface::ajouterCanonnier() {
	int i =HAUTEUR - g->getCoordonneeJoueur().y;
	int j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterCanonnier();
	grille->show();

	return true;
}

bool Interface::ajouterSniper() {
	int i = HAUTEUR - g->getCoordonneeJoueur().y;
	int j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterSniper();
	grille->show();


	return true;
}

bool Interface::ajouterTourBase() {
	int i = HAUTEUR - g->getCoordonneeJoueur().y;
	int j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterTourBase();
	grille->show();


	return true;
}


bool Interface::ajouterBaleine(int i, int j) {
	g->getJoueur()->setPosition(10, 13);
	i = HAUTEUR - g->getCoordonneeJoueur().y;
	j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterBaleine();
	grille->show();


	return true;
}

bool Interface::ajouterSaumon(int i, int j) {
	g->getJoueur()->setPosition(10, 13);
	i = HAUTEUR - g->getCoordonneeJoueur().y;
	j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterSaumon();
	grille->show();


	return true;
}

bool Interface::ajouterRequin(int i, int j) {
	g->getJoueur()->setPosition(10, 13);
	i = HAUTEUR - g->getCoordonneeJoueur().y;
	j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterRequin();
	grille->show();


	return true;
}
