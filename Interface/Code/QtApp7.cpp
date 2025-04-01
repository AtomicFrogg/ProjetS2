#include "QtApp7.h"

QtApp7::QtApp7() : QMainWindow()
{
    this->setFixedSize(600, 600);
    //QMenu* menuFichier = menuBar()->addMenu("&Fichier");

    //QAction* actionOuvrir = new QAction("&Ouvrir", this);
    //QAction* actionSauvegarder = new QAction("&Sauvegarder", this);
    //QAction* actionQuitter = new QAction("&Quitter", this);
    //menuFichier->addAction(actionOuvrir);
    //menuFichier->addAction(actionSauvegarder);
    //menuFichier->addAction(actionQuitter);

    //QMenu* menuTower = menuBar()->addMenu("&TowerDefense");

    //QAction* actionStatistique = new QAction("&Statistique", this);
    //menuTower->addAction(actionStatistique);

    QWidget* zoneCentrale = new QWidget();
    QVBoxLayout* vil = new QVBoxLayout();
    vil->addLayout(outilJeu());
    vil->addWidget(Tours());
    vil->addLayout(enemie());
    zoneCentrale->setLayout(vil);
    setCentralWidget(zoneCentrale);
}

QLayout* QtApp7::outilJeu() {
    QGroupBox* outilJeu = new QGroupBox("instrument", this);
    QGridLayout* layout = new QGridLayout();

    manette = new QRadioButton("manette");
    clavier = new QRadioButton("clavier");
    manette->setChecked(true);

    QVBoxLayout* verticale = new QVBoxLayout;
    verticale->addWidget(manette);
    verticale->addWidget(clavier);
   
    outilJeu->setGeometry(300, 300, 150, 150);
    outilJeu->setLayout(verticale);
    layout->addWidget(outilJeu, 0, 0);
    return layout;
}

QTabWidget* QtApp7::Tours() {
    QGridLayout* layout = new QGridLayout();
    QVBoxLayout* vbox = new QVBoxLayout();
    QFormLayout* formulaire = new QFormLayout();
    
    onglets = new QTabWidget(this);
    onglets->setGeometry(30, 20, 240, 160);

    QWidget* tours = new QWidget();
    QWidget* enemies = new QWidget();

    //page tours
    comboTours = new QComboBox(tours);
    comboTours->addItem("Narvolt");
    comboTours->addItem("Marteau");
    comboTours->addItem("Clou");
    le1 = new QSpinBox();
    le2 = new QSpinBox();
    //organisation
    formulaire->addRow("Type Tour", comboTours);
    formulaire->addRow("Range", le1);
    formulaire->addRow("Damage", le2);
    //BOUTTON
    valider = new QPushButton("valider");
    reset = new QPushButton("reset");

    valider->setFixedSize(70, 30);
    reset->setFixedSize(70, 30);

    layout->addWidget(valider, 1, 1);
    layout->addWidget(reset, 1, 2);

    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valider1()));
    QObject::connect(reset, SIGNAL(clicked()), this, SLOT(reset1()));

    vbox->addLayout(formulaire);
    vbox->addLayout(layout);
    tours->setLayout(vbox);


    //page enemies
    QFormLayout* formulaire2 = new QFormLayout();
    QGridLayout* layout2 = new QGridLayout();
    QVBoxLayout* vbox2 = new QVBoxLayout();
    comboenemie = new QComboBox(enemies);
    comboenemie->addItem("Poisson zombie");
    comboenemie->addItem("Neuci");
    comboenemie->addItem("Pieuvre");
    le12 = new QSpinBox();
    le13 = new QSpinBox();
    le14 = new QSpinBox();
    //organisation
    formulaire2->addRow("Type Enemie", comboenemie);
    formulaire2->addRow("Dommage", le12);
    formulaire2->addRow("vitesse", le13);
    formulaire2->addRow("vie", le14);
    //BOUTTON
    validation = new QPushButton("valider");
    annulation = new QPushButton("reset");

    validation->setFixedSize(70, 30);
    annulation->setFixedSize(70, 30);

    QObject::connect(validation, SIGNAL(clicked()), this, SLOT(valider2()));
    QObject::connect(annulation, SIGNAL(clicked()), this, SLOT(reset2()));

    layout2->addWidget(validation, 1, 1);
    layout2->addWidget(annulation, 1, 2);

    vbox2->addLayout(formulaire2);
    vbox2->addLayout(layout2);
    enemies->setLayout(vbox2);

    onglets->addTab(tours, "Tours");
    onglets->addTab(enemies, "Enemies");
    return onglets;
}

QLayout* QtApp7::enemie() {
    QGridLayout* layout = new QGridLayout();
    ok = new QPushButton("Ok");
    annuler = new QPushButton("Annuler");
    layout->addWidget(ok, 1, 1);
    layout->addWidget(annuler, 1, 2);

    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(soummission()));
    QObject::connect(annuler, SIGNAL(clicked()), qApp, SLOT(quit()));
    return layout;
}

//definition des slots
void QtApp7::reset1() {
    le1->setValue(0);
    le2->setValue(0);
}

void QtApp7::reset2() {
    le12->setValue(0);
    le13->setValue(0);
    le14->setValue(0);
}

bool QtApp7::verification1() {
    QString typeTour;
    int  range, dommage;
    typeTour = comboTours->currentText();
    range = le1->value();
    dommage = le2->value();
    if (range < 10 || dommage < 10) {
        return false;
    }
    else {
        return true;
    }
}

void QtApp7::valider1() {
    QString typeTour;
    int  range, dommage;
    typeTour = comboTours->currentText();
    range = le1->value();
    dommage = le2->value();

    if (!verification1()) {
        QMessageBox::warning(this, "Information Tour", "Ces valeurs sont trop basses pour debuter le jeu!!!");
    }
    else {
        QMessageBox::information(this, "Information Tour", QString("Type Tour:%1<br/>").arg(typeTour) + QString("range:%1<br/>").arg(range) + QString("dommage:%1<br/>").arg(dommage));
    }
}

bool QtApp7::verification2() {
    QString typeEnemie;
    result = false;
    int  vitesse, vie, dommage;
    typeEnemie = comboenemie->currentText();

    dommage = le12->value();
    vitesse = le13->value();
    vie = le14->value();

    if (dommage < 10 || vitesse < 10 || vie < 10) {
        return false;
    }
    else {
        return true;
    }
}

void QtApp7::valider2() {
    QString typeEnemie;
    int  vitesse, vie, dommage;
    typeEnemie = comboenemie->currentText();

    dommage = le12->value();
    vitesse = le13->value();
    vie = le14->value();

    if (!verification2()) {
        QMessageBox::warning(this, "Information Enemie", "Ces valeurs sont trop basses pour debuter le jeu!!!");
    }
    else {
        QMessageBox::information(this, "Information Enemie", QString("Type Enemie:%1<br/>").arg(typeEnemie) + QString("dommage:%1<br/>").arg(dommage) + QString("vitesse:%1<br/>").arg(vitesse) + QString("vie:%1<br/>").arg(vie));
    }
}

void QtApp7::soummission(){
    if (!verification1() || !verification2()) {
        QMessageBox::warning(this, "Information Generale", "Ces valeurs sont trop basses pour debuter le jeu!!!");
    }
    else{
        if (manette->isChecked()) {
            QMessageBox::information(this, "Information Generale", "Vous avez choisir la <strong>manette</strong> pour le jeu!!!");
        }
        else {
            QMessageBox::information(this, "Information Generale", "Vous avez choisir le <strong>clavier</strong> pour le jeu!!!");
        }
    }
}

QtApp7::~QtApp7()
{}
