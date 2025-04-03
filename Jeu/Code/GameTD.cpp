#include <thread>
#include "../Header/Input.h"
#include "../../Tours/Header/Tour.h"
#include "../../Ennemis/Header/Ennemie.h"
#include "../Header/test.h"
#include <qapplication.h>
#include <qpushbutton.h>
#include "../../Interface/Header/Interface.h"
#include "../../Interface/Header/QtApp7.h"
#include "../../Jeu/Header/Application.h"
#include "qfile.h"

int main(int argc, char* argv[]) {


	
	GUI* gui = new GUI();
	/*
	
		Question du d�but (Manette ou clavier, Map et APP7)

	*/
	Application app(gui,argc, argv);


	QFile file("Interface/Code/style.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet{ QLatin1String(file.readAll()) };
	app.setStyleSheet(styleSheet);


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
