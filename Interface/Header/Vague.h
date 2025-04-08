#pragma once
#include "qthread.h"
#include "qdebug.h"
#include "../../Jeu/Header/GUI.h"
#include <iostream>
#include <istream>

using namespace std;
class Vague:public QObject
{
	Q_OBJECT
public :
	Vague();
	bool lancerVague();
	bool afficherEnnemi();
private:
	GUI *g;
};

