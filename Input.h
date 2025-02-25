#pragma once
#include <windows.h>
#include <iostream>
#include "GUI.h"
#include <mutex>

using namespace std;
class Input {
public:

	static void input(GUI* gui);
	int checkKey();
};
