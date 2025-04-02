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
#include <QtWidgets/QSpinBox>
#include "qapplication.h"
#include "qmessagebox.h"

class QtApp7 : public QMainWindow
{
    Q_OBJECT

        public:
            QtApp7();
           QLayout* outilJeu();
           QTabWidget* Tours();
           QLayout* enemie();
           bool verification1();
           bool verification2();
            ~QtApp7();

    public slots:
        void reset1();
        void reset2();
        void valider1();
        void valider2();
        void soummission();

        private:
            QRadioButton* manette;
            QRadioButton* clavier;
            QTabWidget* onglets;
            QComboBox* comboTours;
            QSpinBox* le1;
            QSpinBox* le2;
            QPushButton* valider;
            QPushButton* reset;
            QComboBox* comboenemie;
            QSpinBox* le12;
            QSpinBox* le13;
            QSpinBox* le14;
            QPushButton* validation;
            QPushButton* annulation;
            QPushButton* ok;
            QPushButton* annuler;
            bool result;
        };
