#pragma once
#include <qwidget.h>
#include <qgridlayout.h>
#include "../../Jeu/Header/GUI.h"
#include "Case.h"
#include "qpushbutton.h"
#include "qapplication.h"
class Interface: public QWidget
{
public:
	Interface(GUI *gui);
	~Interface();

	QGridLayout* getLayout();
private:
	QGridLayout* layout;
};

