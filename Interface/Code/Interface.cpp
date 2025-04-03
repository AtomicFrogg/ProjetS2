#include "../Header/Interface.h"

Interface::Interface(GUI *gui)
{
	g = gui;
	Case* image;
	layout = new QGridLayout;
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

	QPushButton *Canon = new QPushButton("Canonnier");
	Canon->setCursor(Qt::PointingHandCursor);
	QObject::connect(Canon, SIGNAL(clicked()), this, SLOT(ajouterCanonnier()));
	layout->addWidget(Canon, 1, LARGEUR);

	QPushButton* Narv = new QPushButton("Narvolt");
	Narv->setCursor(Qt::PointingHandCursor);
	QObject::connect(Narv, SIGNAL(clicked()), this, SLOT(ajouterNarvolt()));
	layout->addWidget(Narv, 2, LARGEUR);

	QPushButton* Sni = new QPushButton("Sniper");
	Sni->setCursor(Qt::PointingHandCursor);
	QObject::connect(Sni, SIGNAL(clicked()), this, SLOT(ajouterSniper()));
	layout->addWidget(Sni, 3, LARGEUR);

	QPushButton* TB = new QPushButton("Tour de Base");
	TB->setCursor(Qt::PointingHandCursor);
	QObject::connect(TB, SIGNAL(clicked()), this, SLOT(ajouterTourBase()));
	layout->addWidget(TB, 4, LARGEUR);

	QPushButton* Jou = new QPushButton("Joueur");
	Jou->setCursor(Qt::PointingHandCursor);
	QObject::connect(Jou, SIGNAL(clicked()), this, SLOT(ajouterJoueur()));
	layout->addWidget(Jou, 5, LARGEUR);

	//QPushButton* quit = new QPushButton("QUITTER");
	//quit->setCursor(Qt::PointingHandCursor);
	//QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	//layout->addWidget(quit, HAUTEUR, 1);

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
	if (!g->ajouterTourNarvolt())
	{
		return false;
	}
	int i = HAUTEUR - g->getCoordonneeJoueur().y;
	int j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterNarvolt();
	grille->show();

	

	return true;
}

bool Interface::ajouterCanonnier() {
	if (!g->ajouterTourCanonnier())
	{
		return false;
	}
	int i =HAUTEUR - g->getCoordonneeJoueur().y;
	int j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterCanonnier();
	grille->show();

	return true;
}

bool Interface::ajouterSniper() {
	if (!g->ajouterTourSniper())
	{
		return false;
	}
	int i = HAUTEUR - g->getCoordonneeJoueur().y;
	int j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterSniper();
	grille->show();


	return true;
}

bool Interface::ajouterTourBase() {
	if (!g->ajouterTourBase())
	{
		return false;
	}
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

bool Interface::ajouterJoueur()
{
	int i = HAUTEUR - g->getJoueur()->getPosition().y;
	int j = g->getCoordonneeJoueur().x;
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterJoueur();
	grille->show();
}