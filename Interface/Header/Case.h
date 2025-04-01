#pragma once
#include <qlabel.h>
#include <iostream>
#include <../../Jeu/Header/GUI.h>
#include <qobject.h>
const int CARRE = 30;
class Case: public QLabel
{
//Q_OBJECT
	public:
		Case(QWidget* parent = nullptr, int t = 0, GUI* g = nullptr, int posi = 0, int posj = 0);
		~Case();
		void choixBackground(int type);

	public slots:
		void ajouterNarvolt();
		void ajouterCanonnier();
		void ajouterSniper();
		void ajouterTourBase();

		void ajouterBaleine();
		void ajouterSaumon();
		void ajouterRequin();


		void clearImage();

	private:
		GUI* gui;
		int type;
		int i;
		int j;
		QLabel* image;
};
