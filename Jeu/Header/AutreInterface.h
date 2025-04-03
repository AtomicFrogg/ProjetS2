#include <qapplication.h>
#include "../../Interface/Header/Interface.h"

class AutreInterface: public QApplication
{
   QObject
   AutreInterface(GUI* g);
   ~AutreInterface();

   public:
   bool getInterface();

   private:
   Interface* window(g);
}