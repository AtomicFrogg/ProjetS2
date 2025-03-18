#include "../Header/Input.h"
static SerialPort* arduino; //doit etre un objet global!

int boutonUp = 0;
int  Direction_joystick = 0;

void Input::input(GUI* gui)
{
	cout << "Voulez-vous jouer manette ou clavier?" << endl << "1: Manette" << endl << "2: Clavier" << endl;
	char peripherique;
	cin >> peripherique;
	int time;
	cout << "Choisissez quelle carte vous d�sirez jouer:" << endl << "1: Facile" << endl;
	int choixMap;
	cin >> choixMap;
	gui->chooseMap(choixMap);
	debut = true;
	switch (peripherique)
	{
	case '1':
		cout << "Vous avez choisi la manette" << endl;
		while (!FIN)
		{
			string raw_msg;

			// Initialisation du port de communication
			string com;
			cout << "Entrer le port de communication du Arduino: ";
			cin >> com;
			arduino = new SerialPort(com.c_str(), BAUD);

			//const char com = "\\\\.\\COM3";
			//SerialPort arduino = SerialPort("\\\\.\\COM3");
			if (!arduino->isConnected()) {
				cerr << "Impossible de se connecter au port " << string(com) << ". Fermeture du programme!" << endl;
				exit(1);
			}

			// Structure de donnees JSON pour envoie et reception
			int led_state = 1;
			int ledv_state = 1;
			int ledy_state = 1;
			json j_msg_send; //= "{\"ledr\",\"ledv\",\"ledy\"}";
			json j_msg_rcv;

			// Boucle pour tester la communication bidirectionnelle Arduino-PC
			for (int i = 0; i < 500; i++) {
				// Envoie message Arduino
				j_msg_send["ledv"] = ledv_state;
				j_msg_send["ledr"] = led_state;
				j_msg_send["ledy"] = ledy_state;

				if (!SendToSerial(arduino, j_msg_send)) {
					cerr << "Erreur lors de l'envoie du message. " << endl;
				}

				// Reception message Arduino
				j_msg_rcv.clear(); // effacer le message precedent
				if (!RcvFromSerial(arduino, raw_msg)) {
					cerr << "Erreur lors de la reception du message. " << endl;
				}

				// Impression du message de l'Arduino si valide
				if (raw_msg.size() > 0) {
					//cout << "raw_msg: " << raw_msg ;  // debug
					// Transfert du message en json
					j_msg_rcv = json::parse(raw_msg);
					cout << "Message de l'Arduino: " << j_msg_rcv;

					//comment assigner valeur voir ci-dessous
					boutonUp = j_msg_rcv["boutonUp"];
					Direction_joystick = j_msg_rcv["joystick"];
					cout << " test_boutonUp:" << boutonUp << " test_joystick:" << Direction_joystick << "\r";
					time = 0;
					//Haut
					if (Direction_joystick == 4)
					{
						time = 1;
						//cout << "W" ;

						gui->moveJoueurUp(1);

					}
					//Gauche key
					if (Direction_joystick == 3)
					{
						time = 1;
						//cout << "A" ;

						gui->moveJoueurGauche(1);

					}
					//Bas key
					if (Direction_joystick == 2)
					{
						time = 1;
						//cout << "S" ;

						gui->moveJoueurDown(1);

					}
					//Droite key
					if (Direction_joystick == 1)
					{
						time = 1;
						//cout << "D";

						gui->moveJoueurDroite(1);

					}
					//Haut-Droite
					if (Direction_joystick == 5)
					{
						time = 1;
						//cout << "D";

						gui->moveJoueurDroite(1);
						gui->moveJoueurUp(1);

					}
					//Bas-Droite
					if (Direction_joystick == 6)
					{
						time = 1;
						//cout << "D";

						gui->moveJoueurDroite(1);
						gui->moveJoueurDown(1);

					}
					//Bas-Gauche
					if (Direction_joystick == 7)
					{
						time = 1;
						//cout << "D";

						gui->moveJoueurGauche(1);
						gui->moveJoueurDown(1);

					}
					//Haut-Gauche
					if (Direction_joystick == 8)
					{
						time = 1;
						//cout << "";

						gui->moveJoueurGauche(1);
						gui->moveJoueurUp(1);

					}
					//Down Button
					if (j_msg_rcv["boutonDown"])
					{
						time = 1;
						std::mutex mutex;
						mutex.lock();
						gui->ajouterTourBase();
						mutex.unlock();
					}
					//Up Button
					if (j_msg_rcv["boutonUp"])
					{
						time = 1;
						std::mutex mutex;
						mutex.lock();
						gui->ajouterTourCanonnier();
						mutex.unlock();
					}
					//Left Button
					if (j_msg_rcv["boutonLeft"])
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
					if (j_msg_rcv["boutonRight"])
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
					if (time >= 1)
					{
						Sleep(150);
						//gui->getJoueur()->afficher(cout);
						gui->draw();

						if (time == 2)
						{
							cout << "Impossible d'ameliorer" << endl;
						}
						if (time == 3)
						{
							cout << "amelioration reussi" << endl;
						}
					}


				}

				//Changement de l'etat led
				led_state = !led_state;
				ledv_state = !ledv_state;
				ledy_state = !ledy_state;
				// Bloquer le fil pour environ 1 sec
				Sleep(75); // 75ms
			}





		}

		break;
	case '2':
		cout << "Vous avez choisi le clavier" << endl;

		while (!FIN)
		{
			time = 0;
			//W key
			if (GetAsyncKeyState(87) & 0x8000)
			{
				time = 1;
				//cout << "W" ;

				gui->moveJoueurUp(1);

			}
			//A key
			if (GetAsyncKeyState(65) & 0x8000)
			{
				time = 1;
				//cout << "A" ;

				gui->moveJoueurGauche(1);

			}
			//S key
			if (GetAsyncKeyState(83) & 0x8000)
			{
				time = 1;
				//cout << "S" ;

				gui->moveJoueurDown(1);

			}
			//D key
			if (GetAsyncKeyState(68) & 0x8000)
			{
				time = 1;
				//cout << "D";

				gui->moveJoueurDroite(1);

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
				//gui->getJoueur()->afficher(cout);
				gui->draw();

				if (time == 2)
				{
					cout << "Impossible d'ameliorer" << endl;
				}
				if (time == 3)
				{
					cout << "amelioration reussi" << endl;
				}
			}
			//cout << i << endl
		}
		break;
	default:
		input(gui);
		break;
	}
}


int Input::checkKey()
{
	cout << " Press Any Key:" << endl;
	while (true) {
		// Iterate through all possible key codes (0 to 255)
		for (int keyCode = 0; keyCode < 256; ++keyCode) {
			// Check if the key with keyCode is currently
			// pressed
			if (GetAsyncKeyState(keyCode) & 0x8000) {
				// Convert the key code to ASCII character
				char keyChar = static_cast<char>(keyCode);
				cout << "Pressed Key: " << keyChar
					<< " (ASCII value: " << keyCode << ")"
					<< endl;
			}
		}

		// Add a small delay to avoid high CPU usage
		Sleep(100);
	}

	return 0;
}


void Input::debutJeu()
{
	while (!debut)
	{
		Sleep(100);
	}
}


/*---------------------------Definition de fonctions ------------------------*/
bool SendToSerial(SerialPort* arduino, json j_msg) {
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

// Version fonctionnelle dans VScode et Visual Studio
	buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
	str_buffer.assign(char_buffer, buffer_size);
	msg.append(str_buffer);

	//msg.pop_back(); //remove '/n' from string

	return true;
}

