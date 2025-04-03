#include <qapplication.h>
#include "../../Interface/Header/Interface.h"

class Application: public QApplication
{
	public:
		Application(GUI* g,int argc,char *argv[]);
		~Application();
		Interface* getInterface();

	private:
		Interface* window;
};