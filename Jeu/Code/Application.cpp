#include "../Header/Application.h"

Application::Application(GUI* g,int argc, char* argv[]):QApplication(argc,argv)
{
    window = new Interface(g);
}

Application::~Application()
{
    delete window;
}

Interface * Application::getInterface()
{
    return window;
}