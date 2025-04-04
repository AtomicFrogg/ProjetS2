#include "../Header/Application.h"

Application::Application(GUI* g,int argc, char* argv[]):QApplication(argc,argv)
{
    gui = g;
    firstWindow = new QtApp7(g);
    firstWindow->show();
}

Application::~Application()
{
}

QtApp7* Application::getApp()
{
    return firstWindow;
}