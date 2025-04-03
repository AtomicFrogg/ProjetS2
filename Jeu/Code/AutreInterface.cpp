#include "../Header/AutreInterface.h"

AutreInterface::AutreInterface(GUI* g):QApplication()
{
    window = new Interface(g);
}

AutreInterface::~AutreInterface()
{
    delete window;
}

Interface* AutreInterface::getInterface()
{
    return window;
}