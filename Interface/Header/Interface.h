#pragma once
#define WIN32_LEAN_AND_MEAN t
#include <Windows.h>
#include <thread>
#include <qwidget.h>
#include <qgridlayout.h>
#include "../../Jeu/Header/GUI.h"
#include "Case.h"
#include "qpushbutton.h"
#include "qapplication.h"
#include "qobject.h"
#include "qmessagebox.h"
#include <QKeyEvent>
#include <ctime>
#include <iostream>
#include "qThreadInput.h"
#include "Vague.h"
#include <QThread>
#include "Vague.h"
#include <QString>
#include <QException>


static bool FIRSTTIME = true;

class Interface: public QWidget
{
Q_OBJECT
public:
	Interface(GUI *gui);
	~Interface();

	QGridLayout* getLayout();
	Case* getCase(int i, int j);
public slots:
	bool ajouterNarvolt();
	bool ajouterCanonnier();
	bool ajouterSniper();
	bool ajouterTourBase();
	bool afficherEnnemi(int index);

	bool ajouterBaleine(int i, int j);
	bool ajouterSaumon(int i, int j);
	bool ajouterRequin(int i, int j);
	bool ajouterEnnemi(int type, int i, int j);
	bool clearJoueur();
	bool ajouterJoueur();
	bool frontMoveJoueur(int d);

	bool joueurUp();
	bool joueurDown();
	bool joueurGauche();
	bool joueurDroite();
	bool MenuDroite();
	bool lancerVague();
	void afficher();
	void afficherStatus();
	void afficherErreurTour();
	bool clearEnnemi();

	void keyPressEvent(QKeyEvent* event) override;

signals:
	void finJeu();
private:
	QVBoxLayout* VboxBoutton;
	QHBoxLayout* Hbox;
	QGridLayout* layout;
	map<string, Case*> grille;
	GUI* g;
	QThread* threadInput;
	QThread* threadVague;
	QLabel* prixTours;
	QLabel* status;
};

