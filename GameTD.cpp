#include <thread>
#include "Input.h"
#include "Tour.h"
#include "Ennemie.h"
#include "test.h"
#include <thread>


int main() {
	GUI* gui = new GUI();
	Input test;

	thread t(&Input::input, gui);
	//test.checkKey();
	test.debutJeu();
	gui->lancerVague(10);
		//Met ton code ici Ric


	FIN = true;
	t.join();
return 0;
}
