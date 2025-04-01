#include <thread>
#include "../Header/Input.h"
#include "../../Tours/Header/Tour.h"
#include "../../Ennemis/Header/Ennemie.h"
#include "../Header/test.h"
#include <qapplication.h>
#include <qpushbutton.h>
#include "../../Interface/Header/Interface.h"

int main(int argc, char* argv[]) {
	GUI* gui = new GUI();
	/*
	
		Question du début (Manette ou clavier, Map et APP7)

	*/
	gui->chooseMap(2);
	QApplication app(argc, argv);
	Interface window(gui);
	window.show();
	app.exec();

	
	//Input test;

	//thread t(&Input::input, gui);
	////test.checkKey();
	//test.debutJeu();
	//gui->lancerVague(40);


	//FIN = true;
	//t.join();
return 0;
}
