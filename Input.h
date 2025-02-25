#pragma once
#include <windows.h>
#include <iostream>
#include <thread>
#include <mutex>
#include "GUI.h"
mutex lockMutex;
static bool FIN = false;
using namespace std;


class Input {
public:
	void input(GUI* gui);
	int checkKey();
};
