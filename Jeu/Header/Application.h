#pragma once

#include <qapplication.h>
#include "../../Interface/Header/QtApp7.h"

class Application: public QApplication
{
	public:
		Application(GUI* g,int argc, char *argv[]);
		~Application();
		QtApp7* getApp();

	private:
		GUI* gui;
		QtApp7* firstWindow;
};