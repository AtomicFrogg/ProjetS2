#pragma once
#include <qlabel.h>
#include <iostream>
#include <../../Jeu/Header/GUI.h>
#include <qobject.h>
#include <string>
const int CARRE = 40;
class Case: public QLabel
{
Q_OBJECT
	public:
		Case(QWidget* parent = nullptr, int t = 0, GUI* g = nullptr, int posi = 0, int posj = 0);
		~Case();
		void choixBackground(int type);

	public slots:
		void ajouterNarvolt();
		void ajouterCanonnier();
		void ajouterSniper();
		void ajouterTourBase();
		void ajouterJoueur();

		void ajouterBaleine();
		void ajouterSaumon();
		void ajouterRequin();


		void clearImage();
		QLabel* getImage();
	private:
		GUI* gui;
		int type;
		int i;
		int j;
		QLabel* image;
};
