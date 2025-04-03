#include "../Header/Application.h"

Application::Application(GUI* g)
{
    window = new Interface(g);
}

Application::~Application()
{
    delete window;
}

Application::getInterface()
{
    return window;
}