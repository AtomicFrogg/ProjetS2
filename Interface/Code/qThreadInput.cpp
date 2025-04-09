#include "../Header/qThreadInput.h"

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
bool muon = true;

InputThread::InputThread(GUI* g)
{
	gui = g;
}
InputThread::~InputThread()
{
	
}


void InputThread::process()
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
	/*int led_state = 0;
	int ledv_state = 0;
	int ledy_state = 0;*/
	while (!FININPUT)
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
		j_msg_send["muon"] = muon;
		muon = false;

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
			else if (Direction_joystick == 3)
			{
				time = 1;
				//std::cout << "A" ;

				manette2key(0x41);

			}
			//Bas key
			else if (Direction_joystick == 2)
			{
				time = 1;
				//std::cout << "S" ;

				manette2key(0x53);

			}
			//Droite key
			else if (Direction_joystick == 1)
			{
				time = 1;
				//std::cout << "D";

				manette2key(0x44);

			}
			//Haut-Droite
			else if (Direction_joystick == 5)
			{
				time = 1;
				//std::cout << "DH";
				manette2key(0x44);
				manette2key(0x57);


			}
			//Bas-Droite
			else if (Direction_joystick == 6)
			{
				time = 1;
				//std::cout << "DB";

				manette2key(0x44);
				manette2key(0x53);

			}
			//Bas-Gauche
			else if (Direction_joystick == 7)
			{
				time = 1;
				//std::cout << "GB";

				manette2key(0x41);
				manette2key(0x53);

			}
			//Haut-Gauche
			else if (Direction_joystick == 8)
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
				if (gui->getDonneesJoueur()->type >= 2)
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
				if (gui->getDonneesJoueur()->type >= 2)
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
				emit nbrMuon(j_msg_rcv["muon"]);
				manette2key(0x46);
				
			}
			if (time >= 1)
			{
				Sleep(200);
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
		Sleep(100);




	}

	emit finished();

}



void InputThread::manette2key(int key)
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


/*---------------------------DeFININPUTition de fonctions ------------------------*/
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
