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
#include "../../Jeu/Header/GUI.h"

class QtApp7 : public QMainWindow
{
    Q_OBJECT

        public:
           QtApp7(GUI* g);
           QLayout* outilJeu();
           QTabWidget* Tours();
           QLayout* enemie();
           void tourW();
           void enemieW();
           void joueurW();
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
            GUI* gui;
            QRadioButton* manette;
            QRadioButton* clavier;
            QTabWidget* onglets;
            QComboBox* comboWidgets;
            QSpinBox* le1;
            QSpinBox* le2;
            QSpinBox* le3;
            QSpinBox* le4;
            QPushButton* valider;
            QPushButton* reset;
            QFormLayout* formulaire;
            QWidget* enemies;
            QWidget* tours;
            QWidget* Joueur;
            bool result;
        };
