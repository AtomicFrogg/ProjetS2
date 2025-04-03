#pragma once

#include <qapplication.h>
#include "../../Interface/Header/Interface.h"
#include "../../Interface/Header/QtApp7.h"

class Application: public QApplication
{
	public:
		Application(GUI* g,int argc, char *argv[]);
		~Application();
		Interface* getInterface();

	private:
		QtApp7* firstWindow;
		Interface* window;
};