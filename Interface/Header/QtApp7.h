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
           QLayout* ennemie();
           void tourW();
           void ennemieW();
           void joueurW();
           bool verification1();
           bool verification2();
           bool verification3();

            ~QtApp7();

    public slots:
        void reset1();
        void reset2();
        void reset3();
        void valider1();
        void valider2();
        void valider3();
        void soummission();

        private:
            GUI* gui;
            QRadioButton* manette;
            QRadioButton* clavier;
            QTabWidget* onglets;
            QComboBox* comboWidgets;
            QComboBox* comboTours;
            QComboBox* comboennemie;
            QSpinBox* le1;
            QSpinBox* le2;
            QSpinBox* le3;
            QSpinBox* le4;
            QSpinBox* le11;
            QSpinBox* le12;
            QSpinBox* le13;
            QSpinBox* le14;
            QSpinBox* le21;
            QSpinBox* le22;
            QSpinBox* le23;
            QSpinBox* le24;
            QPushButton* valider;
            QPushButton* reset;
            QFormLayout* formulaire;
            QWidget* ennemies;
            QWidget* tours;
            QWidget* Joueur;
            bool result;
        };
