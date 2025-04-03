#pragma once
#include <Windows.h>
#include <iostream>
#include <thread>
#include <mutex>
#include "GUI.h"
#include "../../Interface/Header/Interface.h"
#include <mutex>
static bool FIN = false;
static bool debut = false;
using namespace std;
#include "includeJson/serial/SerialPort.hpp"
#include "includeJson/json.hpp"
using json = nlohmann::json;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 115200           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message
/*------------------------- Prototypes de fonctions -------------------------*/
bool SendToSerial(SerialPort* arduino, json j_msg);
bool RcvFromSerial(SerialPort* arduino, string& msg);


/*---------------------------- Variables globales ---------------------------*/



class Input {
public:

	static void input(GUI* gui);
	int checkKey();
	void debutJeu();
};


