#include <qapplication.h>
#include "../../Interface/Header/Interface.h"

class Application: public QApplication
{
   QObject
   Application(GUI* g);
   ~Application();

   public:
   bool getInterface();

   private:
   Interface* window(g);
}