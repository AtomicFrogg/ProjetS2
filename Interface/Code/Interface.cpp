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

	//threadInput = new std::thread(&Interface::input, gui, this);
}

Interface::~Interface()
{
	//threadInput->join();
	//delete threadInput;
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
		std::mutex mutex;
		mutex.lock();
		this->joueurUp();
		mutex.unlock();
	}
	//A key
	if (key == 65)
	{
		time = 1;
		//std::cout << "A" ;
		std::mutex mutex;
		mutex.lock();
		this->joueurGauche();
		mutex.unlock();
	}
	//S key
	if (key == 83)
	{
		time = 1;
		//std::cout << "S" ;
		std::mutex mutex;
		mutex.lock();
		this->joueurDown();
		mutex.unlock();

	}
	//D key
	if (key == 68)
	{
		time = 1;
		//std::cout << "D";
		std::mutex mutex;
		mutex.lock();
		this->joueurDroite();
		mutex.unlock();
	}

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
	if(type == 1)
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
		return true
	}
	else
	{
		return false;
	}
}

bool Interface::afficherEnnemi()
{
	int count, type, i, j;
	for(count = 0; count <= g->getCarte()->getTailleEnnemie(); count++)
	{
		type = g->getCarte()->getEnnemie()->getEnnemie(count)->type;
		i = g->getCarte()->getEnnemie()->getEnnemie(count)->getCoordonnee().y;
		j = g->getCarte()->getEnnemie()->getEnnemie(count)->getCoordonnee().x;
		Case* grille = getCase(i, j);
		grille->clearImage();
		ajouterEnnemi(type, i, j);
	}
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
	if (i < 0 || i > HAUTEUR || j < 1 || j > LARGEUR - 1)
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
		std::cout << g->getCoordonneeJoueur().y << endl;
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
        g->getCarte()->debutEnnemie(index);
        Dimension coord;
        coord.x = 0;
        coord.y = 9;
        for (int i = 0; i < g->getCarte()->getTailleEnnemie(); i++)
        {
            g->getCarte()->getEnnemie()->getEnnemie(i)->setCoordonnee(coord);
        }    
        clock_t start;
        while (g->getCarte()->getVie() > 0 and g->getCarte()->getTailleEnnemie() > 0 and !FINJEU)
        {
            start = clock();
			afficherEnnemi();
            g->moveEnnemies();
            g->getJoueur()->attaquer();
            int time = clock() - start;
            if (time < 700)
            {
                Sleep(700-time);
            }
        }
        g->setFin(true);
        return true;
        //draw();
       /* cout << "Baleine :" << c->getCoordonnee(0).x;
        cout << "vie: " << c->getEnnemie()->getEnnemie(0)->getVie();*/
    }
	return true;
}

static SerialPort* arduino; //doit etre un objet global!

int boutonUp = 0;
int  Direction_joystick = 0;
int led_state = 0;
int ledv_state = 0;
int ledy_state = 0;
int boutUp = 0;
int boutDown = 0;
int boutLeft = 0;
int boutRight = 0;
bool accel = false;
int vie = 1;

void Interface::input(GUI* gui, Interface* interf)
{
	bool peripherique;
	peripherique = gui->getManette();
	int time;
	int choixMap;
	choixMap = gui->getNumCarte();
	debut = true;
	nlohmann::json j_msg_send;
	nlohmann::json j_msg_rcv;

	string com;
	string raw_msg;
	switch (peripherique)
	{
	case 1:

		std::cout << "Vous avez choisi la manette" << endl;

		// Initialisation du port de communication

		//std::cout << "Entrer le port de communication du Arduino: ";
		//cin >> com;
		com = "com6";
		arduino = new SerialPort(com.c_str(), BAUD);
		//int led_state = 1;
		//int ledv_state = 1;
		//int ledy_state = 1;
		while (!FIN)
		{


			//const char com = "\\\\.\\COM3";
			//SerialPort arduino = SerialPort("\\\\.\\COM3");
			if (!arduino->isConnected()) {
				//QMessageBox::information(interf, "Erreur", "La manette n'est pas connect�e");
				//cerr << "Impossible de se connecter au port " << string(com) << ". Fermeture du programme!" << endl;
			}

			// Structure de donnees JSON pour envoie et reception
			vie = gui->getCarte()->getVie();
			if (vie >= 66)
			{
				ledv_state = 1;
				ledy_state = 1;
				led_state = 1;
			}
			else if (vie >= 33)
			{
				ledv_state = 0;
				ledy_state = 1;
				led_state = 1;
			}
			else
			{
				//std::cout << vie<<endl;
				ledv_state = 0;
				ledy_state = 0;
				led_state = 1;
			}
			j_msg_send["ledv"] = ledv_state;
			j_msg_send["ledr"] = led_state;
			j_msg_send["ledy"] = ledy_state;
			j_msg_send["argent"] = gui->getCarte()->getArgent();
			j_msg_send["vie"] = gui->getCarte()->getVie();
			//std::cout << j_msg_send;
			if (!SendToSerial(arduino, j_msg_send)) {
				std::cout << "Erreur lors de l'envoie du message. " << endl;
			}

			// Reception message Arduino
			j_msg_rcv.clear(); // effacer le message precedent
			if (arduino->isConnected())
			{
				if (!RcvFromSerial(arduino, raw_msg)) {
					std::cout << "Erreur lors de la reception du message. " << endl;
				}
			}

			// Impression du message de l'Arduino si valide
			std::cout << "message " << raw_msg.size() << endl;
			if (raw_msg.size() > 0) {
				//std::cout << raw_msg.size() << "\n";
				//std::cout  << raw_msg << "\n";			// Boucle pour tester la communication bidirectionnelle Arduino-PC

				//std::cout << "raw_msg: " << raw_msg ;  // debug
				// Transfert du message en json
				j_msg_rcv = nlohmann::json::parse(raw_msg);
				//std::cout << "Message de l'Arduino: " << j_msg_rcv;

				//comment assigner valeur voir ci-dessous
				Direction_joystick = j_msg_rcv["joystick"];
				//std::cout << " test_boutonUp:" << boutonUp << " test_joystick:" << Direction_joystick << "\r";
				time = 0;
				//Haut

				if (Direction_joystick == 4)
				{
					time = 1;
					//std::cout << "W" ;
					std::mutex mutex;
					mutex.lock();
					interf->frontMoveJoueur(4);

				}
				//Gauche key
				if (Direction_joystick == 3)
				{
					time = 1;
					//std::cout << "A" ;
					std::mutex mutex;
					mutex.lock();
					interf->frontMoveJoueur(3);
					mutex.unlock();
				}
				//Bas key
				if (Direction_joystick == 2)
				{
					time = 1;
					//std::cout << "S" ;
					std::mutex mutex;
					mutex.lock();
					interf->frontMoveJoueur(2);
					mutex.unlock();
				}
				//Droite key
				if (Direction_joystick == 1)
				{
					time = 1;
					//std::cout << "D";
					std::mutex mutex;
					mutex.lock();
					interf->frontMoveJoueur(1);
					mutex.unlock();
				}
				//Haut-Droite
				if (Direction_joystick == 5)
				{
					time = 1;
					//std::cout << "D";
					std::mutex mutex;
					mutex.lock();
					interf->frontMoveJoueur(5);
					mutex.unlock();
				}
				//Bas-Droite
				if (Direction_joystick == 6)
				{
					time = 1;
					//std::cout << "D";
					std::mutex mutex;
					mutex.lock();
					interf->frontMoveJoueur(6);
					mutex.unlock();
				}
				//Bas-Gauche
				if (Direction_joystick == 7)
				{
					time = 1;
					//std::cout << "D";
					std::mutex mutex;
					mutex.lock();
					interf->frontMoveJoueur(7);
					mutex.unlock();
				}
				//Haut-Gauche
				if (Direction_joystick == 8)
				{
					time = 1;
					//std::cout << "";
					std::mutex mutex;
					mutex.lock();
					interf->frontMoveJoueur(8);
					mutex.unlock();
				}
				//Down Button
				boutDown = j_msg_rcv["boutonDown"];
				if (boutDown)
				{
					time = 1;
					std::mutex mutex;
					mutex.lock();
					gui->ajouterTourBase();
					mutex.unlock();
				}
				//Up Button
				boutUp = j_msg_rcv["boutonUp"];
				if (boutUp)
				{
					time = 1;
					std::mutex mutex;
					mutex.lock();
					gui->ajouterTourCanonnier();
					mutex.unlock();
				}
				//Left Button
				boutLeft = j_msg_rcv["boutonLeft"];
				if (boutLeft)
				{
					if (gui->getDonneesJoueur()->type >= 2)
					{
						time = gui->ameliorerDegat() + 2;
					}
					time = 1;
					std::mutex mutex;
					mutex.lock();
					gui->ajouterTourSniper();
					mutex.unlock();

				}
				//Right Button
				boutRight = j_msg_rcv["boutonRight"];
				if (boutRight)
				{
					if (gui->getDonneesJoueur()->type >= 2)
					{
						time = gui->ameliorerRange() + 2;
					}
					time = 1;
					std::mutex mutex;
					mutex.lock();
					gui->ajouterTourNarvolt();
					mutex.unlock();
				}
				accel = j_msg_rcv["accelero"];
				if (accel)
				{
					//std::cout << "POKEMON AU COMBAT" << endl;
					std::mutex mutex;
					mutex.lock();
					gui->getJoueur()->attaquerJoueur();
					mutex.unlock();
				}
				if (time >= 1)
				{
					Sleep(150);
					//gui->getJoueur()->afficher(std::cout);
					//gui->draw();

					if (time == 2)
					{
						std::cout << "Impossible d'ameliorer" << endl;
					}
					if (time == 3)
					{
						std::cout << "amelioration reussi" << endl;
					}
				}

			}
			Sleep(75);




		}

		break;
	case 0:
		std::cout << "Vous avez choisi le clavier" << endl;

		while (!FIN)
		{
			time = 0;
			//W key
			if (GetAsyncKeyState(87) & 0x8000)
			{
				time = 1;
				//std::cout << "W" ;

				interf->joueurUp();

			}
			//A key
			if (GetAsyncKeyState(65) & 0x8000)
			{
				time = 1;
				//std::cout << "A" ;

				interf->joueurGauche();

			}
			//S key
			if (GetAsyncKeyState(83) & 0x8000)
			{
				time = 1;
				//std::cout << "S" ;
				std::mutex mutex;
				mutex.lock();
				interf->joueurDown();
				mutex.unlock();

			}
			//D key
			if (GetAsyncKeyState(68) & 0x8000)
			{
				time = 1;
				//std::cout << "D";

				interf->joueurDroite();

			}
			//Enter key
			if (GetAsyncKeyState(13) & 0x8000)
			{
				time = 1;
				bool enter = 0;
				if (enter == 0)
				{
					enter = true;
				}
				if (gui->getCarte()->getTailleEnnemie() <= 0 and enter)
				{
					gui->setFin(false);
				}

			}
			//Space key
			if (GetAsyncKeyState(32) & 0x8000)
			{
				time = 1;

				gui->getJoueur()->attaquerJoueur();
			}
			//Escape key
			if (GetAsyncKeyState(27) & 0x8000)
			{
				time = 1;

				FIN = true;
				gui->setFin(true);
			}
			//E key
			if (GetAsyncKeyState(69) & 0x8000)
			{
				time = 1;
				std::mutex mutex;
				mutex.lock();
				gui->ajouterTourBase();
				mutex.unlock();
			}
			//Q key
			if (GetAsyncKeyState(81) & 0x8000)
			{
				time = 1;
				std::mutex mutex;
				mutex.lock();
				gui->ajouterTourCanonnier();
				mutex.unlock();
			}
			//R key
			if (GetAsyncKeyState(82) & 0x8000)
			{
				time = 1;
				std::mutex mutex;
				mutex.lock();
				gui->ajouterTourSniper();
				mutex.unlock();
			}
			//F key
			if (GetAsyncKeyState(70) & 0x8000)
			{
				time = 1;
				std::mutex mutex;
				mutex.lock();
				gui->ajouterTourNarvolt();
				mutex.unlock();
			}
			//Z key
			if (GetAsyncKeyState(90) & 0x8000)
			{
				if (gui->getDonneesJoueur()->type >= 2)
				{
					time = gui->ameliorerDegat() + 2;
				}
			}
			//X key
			if (GetAsyncKeyState(88) & 0x8000)
			{
				if (gui->getDonneesJoueur()->type >= 2)
				{
					time = gui->ameliorerRange() + 2;
				}

			}
			if (time >= 1)
			{
				Sleep(150);
				//gui->getJoueur()->afficher(std::cout);
				//gui->draw();

				if (time == 2)
				{
					std::cout << "Impossible d'ameliorer" << endl;
				}
				if (time == 3)
				{
					std::cout << "amelioration reussi" << endl;
				}
			}
			//std::cout << i << endl
		}
		break;
	default:
		input(gui,interf);
		break;
	}
}


int Interface::checkKey()
{
	std::cout << " Press Any Key:" << endl;
	while (true) {
		// Iterate through all possible key codes (0 to 255)
		for (int keyCode = 0; keyCode < 256; ++keyCode) {
			// Check if the key with keyCode is currently
			// pressed
			if (GetAsyncKeyState(keyCode) & 0x8000) {
				// Convert the key code to ASCII character
				char keyChar = static_cast<char>(keyCode);
				std::cout << "Pressed Key: " << keyChar
					<< " (ASCII value: " << keyCode << ")"
					<< endl;
			}
		}

		// Add a small delay to avoid high CPU usage
		Sleep(100);
	}

	return 0;
}


void Interface::debutJeu()
{
	while (!debut)
	{
		Sleep(100);
	}
}


/*---------------------------Definition de fonctions ------------------------*/
bool SendToSerial(SerialPort* arduino, nlohmann::json j_msg) {
	// Return 0 if error
	string msg = j_msg.dump();
	bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
	return ret;
}


bool RcvFromSerial(SerialPort* arduino, string& msg) {
	// Return 0 if error
	// Message output in msg
	string str_buffer;
	char char_buffer[MSG_MAX_SIZE];
	int buffer_size;

	msg.clear(); // clear string
	// Read serialport until '\n' character (Blocking)

	// Version fonctionnel dans VScode, mais non fonctionnel avec Visual Studio
/*
	while(msg.back()!='\n'){
		if(msg.size()>MSG_MAX_SIZE){
			return false;
		}

		buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
		str_buffer.assign(char_buffer, buffer_size);
		msg.append(str_buffer);
	}
*/

	buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
	str_buffer.assign(char_buffer, buffer_size);
	msg.append(str_buffer);

	//msg.pop_back(); //remove '/n' from string

	return true;
}

