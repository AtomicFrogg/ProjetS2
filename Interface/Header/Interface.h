#pragma once
#include <qwidget.h>
#include <qgridlayout.h>
#include "../../Jeu/Header/GUI.h"
#include "Case.h"
class Interface: public QWidget
{
public:
	Interface(GUI *gui);
	~Interface();

private:
	QGridLayout* layout;
};

