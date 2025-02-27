#pragma once
#include "Tour.h"
struct Donnees
{
	//0 = ennemi
	//1 = chemin
	//2 = tourBase
	//3 = Sniper
	//4 = Canonnier
	//5 = Narvolt
	int type;
	Tour* ptr;
	int index;
};