#pragma once
#include <Windows.h>
#include <iostream>
#include <thread>
#include <mutex>
#include "GUI.h"
#include <mutex>
static bool FIN = false;
static bool debut = false;
using namespace std;
class Input {
public:

	static void input(GUI* gui);
	int checkKey();
	void debutJeu();
};


