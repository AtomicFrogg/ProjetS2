#include "../Header/Interface.h"



Interface::Interface(GUI *gui)
{
	g = gui;
	Case* image;
	layout = new QGridLayout;
	Hbox = new QHBoxLayout;
	VboxBoutton = new QVBoxLayout;
	prixTours = new QLabel;
	status = new QLabel;
	

	this->setFixedHeight(590);

	for (int i = 1; i < HAUTEUR ; i++)
	{
		for (int j = 1; j < LARGEUR - 1; j++)
		{
			int type = gui->getDonnees(HAUTEUR-i, j)->type;

			image = new Case(this,type,gui,i,j);
			//image->setFixedSize(30, 30);


			string nom = "Case";
			nom += std::to_string(i);
			nom.append(";");	
			nom += std::to_string(j);
			std::cout << nom << endl;
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
		//MenuDroite();
		Hbox->addLayout(VboxBoutton, 1);
	}
	else
	{
		//cr�ation du thread pour la manette
		InputThread* fonctionInput = new InputThread(gui);
		threadInput = new QThread;
		fonctionInput->moveToThread(threadInput);
		QObject::connect(threadInput, &QThread::started, fonctionInput, &InputThread::process);
		QObject::connect(fonctionInput, &InputThread::finished, fonctionInput, &QThread::deleteLater);
		QObject::connect(fonctionInput, &InputThread::finished, threadInput, &InputThread::deleteLater);
		QObject::connect(fonctionInput, &InputThread::finished, threadInput, &QThread::quit);
		
		threadInput->start();


		//threadInput = new std::thread{ &Interface::manetteInput, g};
	}

	//creation du thread pour lancer vague
	Vague* fonctionVague = new Vague(g);
	threadVague = new QThread;
	fonctionVague->moveToThread(threadVague);
	QObject::connect(threadVague, &QThread::started, fonctionVague, &Vague::lancerVague);
	QObject::connect(fonctionVague, &Vague::finished, threadVague, &QThread::quit);
	QObject::connect(fonctionVague, &Vague::finished, fonctionVague, &QThread::deleteLater);
	QObject::connect(fonctionVague, &Vague::finished, threadVague, &QThread::deleteLater);
	QObject::connect(fonctionVague, SIGNAL(afficherEnnemi(int)), this, SLOT(afficherEnnemi(int)));
	QObject::connect(fonctionVague, &Vague::updateStatus, this, &Interface::afficherStatus);
	QObject::connect(fonctionVague, SIGNAL(clearEnnemi()), this, SLOT(clearEnnemi()));


	QPushButton* Vague = new QPushButton("Lancer Vague");
	Vague->setCursor(Qt::PointingHandCursor);
	Vague->setFixedSize(130, 100);

	afficherStatus();
	VboxBoutton->addWidget(status,0);

	prixTours->setMinimumWidth(150);
	VboxBoutton->addWidget(prixTours,1);

	QObject::connect(Vague, SIGNAL(clicked()), this, SLOT(lancerVague()));
	VboxBoutton->addWidget(Vague, 2);
	
	

	this->setLayout(Hbox);

	ajouterJoueur();
	afficher();
	//threadVague = new std::thread(&Interface::lancerVague, gui, this);
}

Interface::~Interface()
{
	FININPUT = true;
	//threadVague->join();
	//threadInput->join();
	//delete threadVague;
	delete layout;
}

void Interface::keyPressEvent(QKeyEvent *event)
{
	int key;
	key = event->key();
	cout << "key = " << key<<endl;
	int time = 0;
	//W key
	if (key == 87)
	{
		time = 1;
		//std::cout << "W" ;
		
		this->joueurUp();
		
	}
	//A key
	if (key == 65)
	{
		time = 1;
		//std::cout << "A" ;
		
		this->joueurGauche();
		
	}
	//S key
	if (key == 83)
	{
		time = 1;
		//std::cout << "S" ;
		
		this->joueurDown();
		

	}
	//D key
	if (key == 68)
	{
		time = 1;
		//std::cout << "D";
	
		this->joueurDroite();
		
	}
	if (key == 49)
	{
		ajouterTourBase();
	}
	if (key == 50)
	{
		ajouterNarvolt();
	}
	if (key == 51)
	{
		ajouterCanonnier();
	}
	if (key == 52)
	{
		ajouterSniper();
	}
	if (key == 69)
	{
		if(g->getDonneesJoueur()->type >= 2) g->ameliorerRange();
	}
	if (key == 81)
	{
		if (g->getDonneesJoueur()->type >= 2) g->ameliorerDegat();
	}
	if (key == 70)
	{
		g->getJoueur()->attaquerJoueur();
	}
	afficher();
	afficherStatus();
	//afficherEnnemi();
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
		afficherErreurTour();
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
		afficherErreurTour();
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
		afficherErreurTour();
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
		afficherErreurTour();
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
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterBaleine();
	grille->show();
	return true;
}

bool Interface::ajouterSaumon(int i, int j) {
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterSaumon();
	grille->show();
	return true;
}

bool Interface::ajouterRequin(int i, int j) {
	if (i < 0 || i >= HAUTEUR || j < 1 || j > LARGEUR - 1) return false;
	Case* grille = getCase(i, j);
	grille->ajouterRequin();
	grille->show();
	return true;
}

bool Interface::ajouterEnnemi(int type, int i, int j)
{
	if (g->getCoordonneeJoueur().x == j and g->getCoordonneeJoueur().y == HAUTEUR - i)
	{
		ajouterJoueur();
	}
	else if(type == 1)
	{
		ajouterSaumon(i, j);
		return true;
	}
	else if(type == 2)
	{
		ajouterRequin(i, j);
		return true;
	}
	else if(type == 3)
	{
		ajouterBaleine(i, j);
		return true;
	}
	else
	{
		return false;
	}
	this->show();
}

bool Interface::afficherEnnemi(int index)
{
	int count, type, i, j;
	for(count = 0; count < g->getCarte()->getTailleEnnemie(); count++)
	{
		type = g->getCarte()->getEnnemie()->getEnnemie(count)->getType();
		i = g->getCarte()->getEnnemie()->getEnnemie(count)->getCoordonnee().y;
		j = g->getCarte()->getEnnemie()->getEnnemie(count)->getCoordonnee().x;
		ajouterEnnemi(type, HAUTEUR - i, j);
		//cout << j << endl;
		this->show();
	}
	return 1;
}

bool Interface::clearEnnemi()
{
	for (int i = 1; i < HAUTEUR; i++)
	{
		for (int j = 1; j < LARGEUR - 1; j++)
		{
			Case* grille = getCase(i, j);
			if (grille->getType() == 1)
			{
				if(g->getCoordonneeJoueur().x != j and g->getCoordonneeJoueur().y != i) grille->clearImage();
			}
		}
	}
	//int type, i, j;
	//type = g->getCarte()->getEnnemie()->getEnnemie(index)->getType();
	//i = g->getCarte()->getEnnemie()->getEnnemie(index)->getCoordonnee().y;
	//j = g->getCarte()->getEnnemie()->getEnnemie(index)->getCoordonnee().x;
	//if (j > 0 and j < LARGEUR)
	//{
	//	cout << j << endl;
	//	Case* caseeee = getCase(HAUTEUR - i , j);
	//	caseeee->choixBackground(0);
	//	caseeee->show();
	//}
	return 1;
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
	if (i < 0 || i > HAUTEUR - 1 || j < 1 || j > LARGEUR - 1)
	{
		qDebug() << "HAAAA";
		return false;
	}
	Case* grille = getCase(i, j);
	grille->ajouterJoueur();
	grille->show();
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
		std::cout << g->getCoordonneeJoueur().y << endl;
		if (!g->moveJoueurUp(1)) std::cout << "allo";
		ajouterJoueur();
		//std::cout << g->getCoordonneeJoueur().y << endl;
		return true;
	}
	return false;
}

bool Interface::joueurDown()
{
	if (g->getCoordonneeJoueur().y > 1)
	{
		clearJoueur();
		g->moveJoueurDown(1);
		ajouterJoueur();

		return true;
	}
	return false;
}

bool Interface::joueurGauche()
{
	if (g->getCoordonneeJoueur().x > 1)
	{
		clearJoueur();
		g->moveJoueurGauche(1);
		ajouterJoueur();

		return true;
	}
}

bool Interface::joueurDroite()
{
	if (g->getCoordonneeJoueur().x < LARGEUR - 2)
	{
		clearJoueur();
		g->moveJoueurDroite(1);
		ajouterJoueur();

		return true;
	}
	return false;
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
	if(!FINJEU)
	{
		return false;
	}
	else
	{
		if(FIRSTTIME)
		{
			threadVague->start();
			FIRSTTIME = false;
		}
		else
		{
			Vague* fonctionVague = new Vague(g);
			threadVague = new QThread;
			fonctionVague->moveToThread(threadVague);
			QObject::connect(threadVague, &QThread::started, fonctionVague, &Vague::lancerVague);
			QObject::connect(fonctionVague, &Vague::finished, threadVague, &QThread::quit);
			QObject::connect(fonctionVague, &Vague::finished, fonctionVague, &QThread::deleteLater);
			QObject::connect(fonctionVague, &Vague::finished, threadVague, &QThread::deleteLater);
			QObject::connect(fonctionVague, &Vague::afficherEnnemi, this, &Interface::afficherEnnemi);
			QObject::connect(fonctionVague, &Vague::updateStatus, this, &Interface::afficherStatus);
			threadVague->start();
		}
		
	}
	return true;
}



void Interface::afficher()
{
	
	bool type;
	QString msg = "";
	if (g->getDonneesJoueur()->type >= 2)
	{

		int index = g->getDonneesJoueur()->index;
		int prixRange = g->getJoueur()->getTour(index)->getRange() * 200;
		int prixDegat = g->getJoueur()->getTour(index)->getDegat() * 400;

		msg = QString::fromLatin1("<strong>AM�LIORATION: <\strong> <br\><br\><br\>PRIX RANGE : %1 $<br\>PRIX D�GAT: %2 $").arg(prixRange).arg(prixDegat);

	}
	else
	{
		int prixTourBase = g->getJoueur()->DonneesTourBase.prix;
		int prixSniper = g->getJoueur()->DonneesSniper.prix;
		int prixCanonnier = g->getJoueur()->DonneesCanonnier.prix;
		int prixNarvolt = g->getJoueur()->DonneesNarvolt.prix;
		msg = QString::fromLatin1("<strong>PRIX:<\strong> <br\><br\><br\>TOUR BASE : %1 $<br\>CANONNIER : %2 $<br\>NARVOLT : %3 $<br\>SNIPER : %4 $").arg(prixTourBase).arg(prixCanonnier).arg(prixNarvolt).arg(prixSniper);

	}

	prixTours->setText(msg);
	prixTours->show();
}

void Interface::afficherStatus()
{
	int vie = g->getCarte()->getVie();
	int argent = g->getCarte()->getArgent();
	QString msg = QString::fromLatin1("<strong>VIE : <\strong>%1 <br\><strong>ARGENT : <\strong>%2").arg(vie).arg(argent);
	status->setText(msg);
}

void Interface::afficherErreurTour()
{
	QString msg = QString::fromLatin1("EMPLACEMENT INVALIDE");
	status->setText(msg);
}