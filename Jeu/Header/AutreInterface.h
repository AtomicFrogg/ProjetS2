#include <qapplication.h>
#include "../../Interface/Header/Interface.h"

class AutreInterface : public QApplication
{
	public:
		AutreInterface(GUI* g);
		~AutreInterface();
		Interface* getInterface();

	private:
		Interface* window;
};