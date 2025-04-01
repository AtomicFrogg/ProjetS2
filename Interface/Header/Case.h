#pragma once
#include <qlabel.h>
#include <iostream>
#include "../../Jeu/Header/GUI.h"
const int CARRE = 30;
class Case: public QLabel
{
	public:

		Case(QWidget* parent = nullptr, int t = 0, GUI* g = nullptr, int posi = 0, int posj = 0);
		~Case();
		void choixBackground(int type);
		void ajouterNarvolt();
		void ajouterCanonnier();
		void ajouterSniper();
		void ajouterTourBase();
		void clearImage();

	private:
		GUI* gui;
		int type;
		int i;
		int j;
		QLabel* image;
};
