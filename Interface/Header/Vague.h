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
protected:
	void run() override {
		for (int i = 0;i < 400;i++) {
			qDebug() << "Travail en cours dans le thread " << i;
			QThread::sleep(1);
		}
	}

signals:
	void afficherEnnemi();
};

