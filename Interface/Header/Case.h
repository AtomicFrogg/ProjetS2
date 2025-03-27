#pragma once
#include <qlabel.h>
#include <iostream>
const int CARRE = 30;
class Case: public QLabel
{
	public:

		Case(QWidget* parent = nullptr, int type = 0);
		~Case();

	private:

};
