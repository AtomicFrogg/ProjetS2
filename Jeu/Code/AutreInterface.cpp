#include "../Header/AutreInterface.h"

AutreInterface::AutreInterface(GUI* g)
{
    window = new Interface(g);
}

AutreInterface::~AutreInterface()
{
    delete window;
}

AutreInterface::getInterface()
{
    return window;
}