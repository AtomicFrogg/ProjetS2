#include "../Header/Interface.h"

Interface::Interface(GUI *gui)
{
	g = gui;
	Case* image;
	layout = new QGridLayout;
	this->setFixedSize(1000, HAUTEUR*30);
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

	QPushButton *bouton = new QPushButton("Bouton");
	bouton->setCursor(Qt::PointingHandCursor);
	QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(ajouterCanonnier()));



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

Case* Interface::getCase(int i, int j)
{
	string nom = "Case";
	nom += std::to_string(i);
	nom.append(";");
	nom += std::to_string(j);
	Case* lay = grille[nom];
	return grille[nom];
}

bool Interface::ajouterNarvolt(int i, int j) {
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	QMessageBox::critical(this,"Bravo", "Vous avez ajouté une tour!");
	Case* grille = getCase(i, j);
	
	grille->ajouterNarvolt();
	

	return true;
}

bool Interface::ajouterCanonnier() {
	g->getJoueur()->setPosition(10, 13);
	int i =HAUTEUR - g->getCoordonneeJoueur().y;
	int j = g->getCoordonneeJoueur().x;

	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterCanonnier();
	grille->show();

	return true;
}

bool Interface::ajouterSniper(int i, int j) {
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterSniper();

	return true;
}

bool Interface::ajouterTourBase(int i, int j) {
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterTourBase();

	return true;
}


bool Interface::ajouterBaleine(int i, int j) {
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterBaleine();

	return true;
}

bool Interface::ajouterSaumon(int i, int j) {
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterSaumon();

	return true;
}

bool Interface::ajouterRequin(int i, int j) {
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterRequin();

	return true;
}
