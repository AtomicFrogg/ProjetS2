#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadiobutton>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QComboBox>
#include <QtWidgets/qformlayout.h>
#include "ui_QtApp7.h"

class QtApp7 : public QMainWindow
{
    Q_OBJECT

public:
    QtApp7();
   QLayout* outilJeu();
   QTabWidget* Tours();
   QLayout* validation();
    ~QtApp7();

private:
    Ui::QtApp7Class ui;
};
