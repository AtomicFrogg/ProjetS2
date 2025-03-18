#include <thread>
#include "../Header/Input.h"
#include "../../Tours/Header/Tour.h"
#include "../../Ennemis/Header/Ennemie.h"
#include "../Header/test.h"
#include <thread>


int main() {
	GUI* gui = new GUI();
	Input test;

	thread t(&Input::input, gui);
	//test.checkKey();
	test.debutJeu();
	gui->lancerVague(10);


	FIN = true;
	t.join();
return 0;
}
