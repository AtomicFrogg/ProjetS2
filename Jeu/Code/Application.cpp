#include "../Header/Application.h"

Application::Application(GUI* g,int argc, char* argv[]):QApplication(argc,argv)
{
    firstWindow = new QtApp7(g);
    window = new Interface(g);
    firstWindow->show();
}

Application::~Application()
{
    delete window;
}

Interface* Application::getInterface()
{
    return window;
}