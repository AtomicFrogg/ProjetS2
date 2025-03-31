#pragma once
#include <qlabel.h>
#include <iostream>
#include <../../Jeu/Header/GUI.h>
const int CARRE = 30;
class Case: public QLabel
{
	public:

		Case(QWidget* parent = nullptr, int type = 0, GUI* gui = nullptr, int x = 0, int y = 0);
		~Case();

	private:

};
