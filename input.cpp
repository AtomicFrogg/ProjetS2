
#include "Input.h"

void input()
{
	cout << "Voulez-vous jouer manette ou clavier?" << endl << "1: Manette" << endl << "2: Clavier" << endl;
	int peripherique;
	cin >> peripherique;
	int i = 0;
	switch (peripherique)
	{
	case 1:
		cout << "Vous avez choisi la manette" << endl;

		break;
	case 2:
		cout << "Vous avez choisi le clavier2" << endl;

		while (1)
		{
			if (GetKeyState(87) & 0x8000)
			{
				cout << "W" << endl;
			}
			if (GetKeyState(65) & 0x8000)
			{
				cout << "A" << endl;
			}
			if (GetKeyState(83) & 0x8000)
			{
				cout << "S" << endl;
			}
			if (GetKeyState(68) & 0x8000)
			{
				cout << "D" << endl;
			}
			//cout << i << endl;
			i++;
		}
		break;
	default:
		input();
		break;
	}
}


int checkKey()
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