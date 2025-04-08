#pragma once
#include "qdebug.h"
#include <iostream>
#include <istream>
#include "../../Jeu/Header/GUI.h"

using namespace std;
class Vague: public QObject
{
	Q_OBJECT
public :
	Vague(GUI* g);
	~Vague();
	bool lancerVague();

signals:
	void afficherEnnemi();
};

