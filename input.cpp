#include "Input.h"


void Input::input(GUI* gui)
{
	cout << "Voulez-vous jouer manette ou clavier?" << endl << "1: Manette" << endl << "2: Clavier" << endl;
	char peripherique;
	cin >> peripherique;
	bool time;
	switch (peripherique)
	{
	case '1':
		cout << "Vous avez choisi la manette" << endl;

		break;
	case '2':
		cout << "Vous avez choisi le clavier" << endl;

		while (1)
		{
			time = 0;
			if (GetKeyState(87) & 0x8000)
			{
				time = 1;
				cout << "W" ;
				gui->moveJoueurUp(1);

			}
			if (GetKeyState(65) & 0x8000)
			{
				time = 1;
				cout << "A" ;
				gui->moveJoueurGauche(1);
			}
			if (GetKeyState(83) & 0x8000)
			{
				time = 1;
				cout << "S" ;
				gui->moveJoueurDown(1);
			}
			if (GetKeyState(68) & 0x8000)
			{
				time = 1;
				cout << "D";
				gui->moveJoueurDroite(1);
			}
			if (GetKeyState(13) & 0x8000)
			{
				time = 1;
				cout << "Enter";
				
			}
			if (GetKeyState(32) & 0x8000)
			{
				time = 1;
				cout << "Space";
				
			}
			if (GetKeyState(27) & 0x8000)
			{
				time = 1;
				cout << "Esc";
				
			}
			if (GetKeyState(69) & 0x8000)
			{
				time = 1;
				cout << "E";
				gui->ajouterTourBase;
				
			}
			if (GetKeyState(81) & 0x8000)
			{
				time = 1;
				cout << "Q";
<<<<<<< HEAD
				gui->ajouterTourCanonnier;
=======
				gui->ajouterTourCanonnier
>>>>>>> origin/main
			}
			if (GetKeyState(82) & 0x8000)
			{
				time = 1;
				cout << "R";
<<<<<<< HEAD
				gui->ajouterTourSniper;
=======
				gui->ajouterTourSniper
>>>>>>> origin/main
			}
			if (GetKeyState(70) & 0x8000)
			{
				time = 1;
				cout << "F";
<<<<<<< HEAD
				gui->ajouterTourNarvolt;
=======
				gui->ajouterTourNarvolt
>>>>>>> origin/main
			}
			if (time = 1)
			{
				Sleep(100);

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