#pragma once
#include "qdebug.h"
#include <iostream>
#include <istream>
#include "../../Jeu/Header/GUI.h"
static bool CLEAR;

using namespace std;
class Vague: public QObject
{
		Q_OBJECT
	public :
		Vague(GUI *g);
		~Vague();
public slots:
		void lancerVague();
	private:
		GUI* gui;
signals:
	void finished();
signals:
	void afficherEnnemi(int);
signals:
	void updateStatus();
signals:
	void clearEnnemi();

};

