#pragma once
#include <qwidget.h>
#include <qgridlayout.h>
#include "../../Jeu/Header/GUI.h"
#include "Case.h"
#include "qpushbutton.h"
#include "qapplication.h"
#include "qobject.h"
#include "qmessagebox.h"
class Interface: public QWidget
{
Q_OBJECT
public:
	Interface(GUI *gui);
	~Interface();

	QGridLayout* getLayout();
	Case* getCase(int i, int j);
public slots:
	bool ajouterNarvolt();
	bool ajouterCanonnier();
	bool ajouterSniper();
	bool ajouterTourBase();

	bool ajouterBaleine(int i, int j);
	bool ajouterSaumon(int i, int j);
	bool ajouterRequin(int i, int j);
	bool clearJoueur();
	bool ajouterJoueur();
	bool frontMoveJoueur(int d);
private:
	QVBoxLayout* VboxBoutton;
	QHBoxLayout* Hbox;
	QGridLayout* layout;
	map<string, Case*> grille;
	GUI* g;
};

