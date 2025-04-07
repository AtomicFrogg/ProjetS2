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
		g->ameliorerRange();
	}
	if (key == 81)
	{
		g->ameliorerDegat();
	}
	if (key == 70)
	{
		g->getJoueur()->attaquerJoueur();
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
		return true;
	}
	else
	{
		return false;
	}
}

bool Interface::afficherEnnemi()
{
	int count, type, i, j;
	for(count = 0; count < g->getCarte()->getTailleEnnemie(); count++)
	{
		type = g->getCarte()->getEnnemie()->getEnnemie(count)->getType();
		i = g->getCarte()->getEnnemie()->getEnnemie(count)->getCoordonnee().y;
		j = g->getCarte()->getEnnemie()->getEnnemie(count)->getCoordonnee().x;
		ajouterEnnemi(type, i, j);
		this->show();
	}
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
	std::cout << "Je me suis rendu a lancer vague";
	int index = 40;
	if(!FINJEU)
    {
		std::cout << "oops FINJEU est false";
        return false;
    }
    else
    {
		std::cout << "on est dans le else de lancer vague";
        g->getCarte()->debutEnnemie(index);
        Dimension coord;
        coord.x = 0;
        coord.y = 9;
		std::cout << "un" << endl;
        for (int i = 0; i < g->getCarte()->getTailleEnnemie(); i++)
        {
            g->getCarte()->getEnnemie()->getEnnemie(i)->setCoordonnee(coord);
			std::cout << "deux" << endl;
        }    
        clock_t start;
		std::cout << "trois" << endl;
        while (g->getCarte()->getVie() > 0 && g->getCarte()->getTailleEnnemie() > 0 && FINJEU)
        {
			std::cout << "quatre";
            start = clock();
			afficherEnnemi();
            g->moveEnnemies();
            g->getJoueur()->attaquer();
            int time = clock() - start;
			std::cout << "cinq" << endl;
            if (time < 700)
            {
                Sleep(700-time);
            }
        }
        g->setFin(true);
		std::cout << "six" << endl;
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

void Interface::manette2key(int key)
{
	INPUT ip;
	// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	// Press the "A" key
	ip.ki.wVk = key; // virtual-key code for the "a" key
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Release the "A" key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));

}

void Interface::manetteInput()
{
	nlohmann::json j_msg_send;
	nlohmann::json j_msg_rcv;
	string raw_msg;
	int time;
	string com;
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
		vie = g->getCarte()->getVie();
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
		j_msg_send["argent"] = g->getCarte()->getArgent();
		j_msg_send["vie"] = g->getCarte()->getVie();
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
			
				manette2key(0x57);
			

			}
			//Gauche key
			if (Direction_joystick == 3)
			{
				time = 1;
				//std::cout << "A" ;
		
				manette2key(0x41);
			
			}
			//Bas key
			if (Direction_joystick == 2)
			{
				time = 1;
				//std::cout << "S" ;
		
				manette2key(0x53);
			
			}
			//Droite key
			if (Direction_joystick == 1)
			{
				time = 1;
				//std::cout << "D";
			
				manette2key(0x44);
			
			}
			//Haut-Droite
			if (Direction_joystick == 5)
			{
				time = 1;
				//std::cout << "DH";
				manette2key(0x44);
				manette2key(0x57);
	
			
			}
			//Bas-Droite
			if (Direction_joystick == 6)
			{
				time = 1;
				//std::cout << "DB";
			
				manette2key(0x44);
				manette2key(0x53);
			
			}
			//Bas-Gauche
			if (Direction_joystick == 7)
			{
				time = 1;
				//std::cout << "GB";
			
				manette2key(0x41);
				manette2key(0x53);
				
			}
			//Haut-Gauche
			if (Direction_joystick == 8)
			{
				time = 1;
				//std::cout << "GH";
			
				manette2key(0x57);
				manette2key(0x41);
			
			}
			//Down Button
			boutDown = j_msg_rcv["boutonDown"];
			if (boutDown)
			{
				manette2key(0x31);
				
			}
			//Up Button
			boutUp = j_msg_rcv["boutonUp"];
			if (boutUp)
			{
				manette2key(0x32);
			}
			//Left Button
			boutLeft = j_msg_rcv["boutonLeft"];
			if (boutLeft)
			{
				if (g->getDonneesJoueur()->type >= 2)
				{
					manette2key(0x45);
				}
				else
				{
					manette2key(0x33);
				}

			}
			//Right Button
			boutRight = j_msg_rcv["boutonRight"];
			if (boutRight)
			{
				if (g->getDonneesJoueur()->type >= 2)
				{
					manette2key(0x51);
				}
				else
				{
					manette2key(0x34);
				}
			}
			accel = j_msg_rcv["accelero"];
			if (accel)
			{
				//std::cout << "POKEMON AU COMBAT" << endl;
				manette2key(0x46);
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

}