#pragma once
#include <windows.h>
#include <iostream>
#include "GUI.h"

using namespace std;
class Input {
public:
	void input(GUI* gui);
	int checkKey();
};
