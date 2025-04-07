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


#include <iostream>
#include <mutex>
static bool FIN = false;
static bool debut = false;
#include "../../includeJson/serial/SerialPort.hpp"
#include "../../includeJson/json.hpp"


/*------------------------------ Constantes ---------------------------------*/
#define BAUD 115200           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message
/*------------------------- Prototypes de fonctions -------------------------*/
bool SendToSerial(SerialPort* arduino, nlohmann::json j_msg);
bool RcvFromSerial(SerialPort* arduino, string& msg);


/*---------------------------- Variables globales ---------------------------*/


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

	bool ajouterBaleine(int i, int j);
	bool ajouterSaumon(int i, int j);
	bool ajouterRequin(int i, int j);
	bool ajouterEnnemi(int type, int i, int j);
	bool afficherEnnemi();
	bool clearJoueur();
	bool ajouterJoueur();
	bool frontMoveJoueur(int d);

	bool joueurUp();
	bool joueurDown();
	bool joueurGauche();
	bool joueurDroite();
	bool MenuDroite();
	bool lancerVague();

	void keyPressEvent(QKeyEvent* event) override;


	void manette2key(int key);
	void manetteInput();
private:
	QVBoxLayout* VboxBoutton;
	QHBoxLayout* Hbox;
	QGridLayout* layout;
	map<string, Case*> grille;
	GUI* g;
	std::thread* threadInput;
};

