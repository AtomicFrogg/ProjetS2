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
			cout << nom << endl;
			grille[nom] = image;
			layout->addWidget(image,i,j);
		}
	}
	
	layout->setContentsMargins(0,0,0,0);
	layout->setSpacing(0);

	Hbox->setContentsMargins(0, 0, 0, 0);
	Hbox->addLayout(layout, 0);
	if(!g->getManette())
	{
		MenuDroite();
		Hbox->addLayout(VboxBoutton, 1);
	}
	
	QPushButton* Vague = new QPushButton("Lancer Vague");
	Vague->setCursor(Qt::PointingHandCursor);
	Vague->setFixedSize(130, 100);

	QObject::connect(Vague, SIGNAL(clicked()), this, SLOT(lancerVague()));
	VboxBoutton->addWidget(Vague, 0);
	this->setLayout(Hbox);

	ajouterJoueur();
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
	//clearJoueur();
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
		QMessageBox::information(this, "NON", "claude");
		return false;
	}
	//clearJoueur();
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
	//clearJoueur();
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
	//clearJoueur();
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

bool Interface::clearJoueur()
{
	int i = HAUTEUR - g->getJoueur()->getPosition().y;
	int j = g->getCoordonneeJoueur().x;
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->clearJoueur();
	grille->show();
}

bool Interface::ajouterJoueur()
{
	int i = HAUTEUR - g->getJoueur()->getPosition().y;
	int j = g->getCoordonneeJoueur().x;
	if (i < 0 || i > HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterJoueur();
	return true;
}

bool Interface::frontMoveJoueur(int d)
{
	clearJoueur();
	switch (d)
	{
	case 1:
		g->moveJoueurDroite(1);
		break;
	case 2:
		g->moveJoueurDown(1);
		break;
	case 3:
		g->moveJoueurGauche(1);
		break;
	case 4:
		g->moveJoueurUp(1);
		break;
	case 5:
		g->moveJoueurUp(1);
		g->moveJoueurDroite(1);
		break;
	case 6:
		g->moveJoueurDown(1);
		g->moveJoueurDroite(1);
		break;
	case 7:
		g->moveJoueurDown(1);
		g->moveJoueurGauche(1);
		break;
	case 8:
		g->moveJoueurUp(1);
		g->moveJoueurGauche(1);
		break;
	case 9:
		g->moveJoueurUp(1);
		break;
	case 10:
		g->moveJoueurGauche(1);
		break;
	case 11:
		g->moveJoueurDown(1);
		break;
	case 12:
		g->moveJoueurDroite(1);
		break;
	default:
		break;
	}
	ajouterJoueur();
	return true;
}

bool Interface::joueurUp()
{
	if (g->getCoordonneeJoueur().y < HAUTEUR)
	{
		clearJoueur();
		cout << g->getCoordonneeJoueur().y << endl;
		if (!g->moveJoueurUp(1)) cout << "allo";
		ajouterJoueur();
		cout << g->getCoordonneeJoueur().y << endl;
		return true;
	}
	return false;
}

bool Interface::joueurDown()
{
	clearJoueur();
	g->moveJoueurDown(1);
	ajouterJoueur();

	return true;
}

bool Interface::joueurGauche()
{
	clearJoueur();
	g->moveJoueurGauche(1);
	ajouterJoueur();

	return true;
}

bool Interface::joueurDroite()
{
	clearJoueur();
	g->moveJoueurDroite(1);
	ajouterJoueur();

	return true;
}

bool Interface::MenuDroite()
{
	int sizeX = 130;
	int sizeY = 100;
	QPushButton* TB = new QPushButton("Tour de Base");
	TB->setCursor(Qt::PointingHandCursor);
	TB->setFixedSize(sizeX,sizeY);
	QObject::connect(TB, SIGNAL(clicked()), this, SLOT(ajouterTourBase()));
	VboxBoutton->addWidget(TB, 1);

	QPushButton *Canon = new QPushButton("Canonnier");
	Canon->setCursor(Qt::PointingHandCursor);
	Canon->setFixedSize(sizeX,sizeY);
	QObject::connect(Canon, SIGNAL(clicked()), this, SLOT(ajouterCanonnier()));
	VboxBoutton->addWidget(Canon, 2);

	QPushButton* Narv = new QPushButton("Narvolt");
	Narv->setFixedSize(sizeX, sizeY);
	Narv->setCursor(Qt::PointingHandCursor);
	QObject::connect(Narv, SIGNAL(clicked()), this, SLOT(ajouterNarvolt()));
	VboxBoutton->addWidget(Narv, 3);

	QPushButton* Sni = new QPushButton("Sniper");
	Sni->setFixedSize(sizeX, sizeY);
	Sni->setCursor(Qt::PointingHandCursor);
	QObject::connect(Sni, SIGNAL(clicked()), this, SLOT(ajouterSniper()));
	VboxBoutton->addWidget(Sni, 4);

	QPushButton* Jou = new QPushButton("Joueur");
	Jou->setCursor(Qt::PointingHandCursor);
	QObject::connect(Jou, SIGNAL(clicked()), this, SLOT(ajouterJoueur()));
	layout->addWidget(Jou, 5, LARGEUR);

	QPushButton* quit = new QPushButton("QUITTER");
	quit->setCursor(Qt::PointingHandCursor);
	quit->setFixedSize(sizeX, sizeY-50);
	QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	VboxBoutton->addWidget(quit, 6);

	QPushButton* up = new QPushButton("up");
	up->setCursor(Qt::PointingHandCursor);
	up->setFixedSize(sizeX, sizeY - 50);
	QObject::connect(up, SIGNAL(clicked()), this, SLOT(joueurUp()));
	VboxBoutton->addWidget(up, 7);
	return true;
}

bool Interface::lancerVague()
{
	g->lancer(40);
	return true;
}