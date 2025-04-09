#pragma once
#include <QObject>
#include "../../Jeu/Header/GUI.h"
#include <iostream>
#include <mutex>
static bool FININPUT = false;
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




class InputThread : public QObject {
Q_OBJECT
public:
	InputThread(GUI* g);
	~InputThread();

	void manette2key(int key);
public slots:
	void process();


signals:
	void finished();
signals:
	void nbrMuon(int);

private:
	GUI* gui;
};