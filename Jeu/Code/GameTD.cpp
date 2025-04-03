#include <thread>
#include "../Header/Input.h"
#include "../../Tours/Header/Tour.h"
#include "../../Ennemis/Header/Ennemie.h"
#include "../Header/test.h"
#include <qapplication.h>
#include <qpushbutton.h>
#include "../../Interface/Header/Interface.h"
#include "../../Interface/Header/QtApp7.h"
#include "qfile.h"

int main(int argc, char* argv[]) {


	
	GUI* gui = new GUI();
	/*
	
		Question du d�but (Manette ou clavier, Map et APP7)

	*/
	gui->chooseMap(2);
	QApplication app(argc, argv);
	Interface window(gui);
	QtApp7 w;
		
	QFile file("Interface/Code/style.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet{ QLatin1String(file.readAll()) };
	app.setStyleSheet(styleSheet);

    w.show();
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
