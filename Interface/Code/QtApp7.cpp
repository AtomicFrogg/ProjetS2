#include "../Header/QtApp7.h"

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

void QtApp7::tourW() {
    QGridLayout* layout = new QGridLayout();
    QVBoxLayout* vbox = new QVBoxLayout();
    formulaire = new QFormLayout();
    tours = new QWidget();


    //page tours
    comboWidgets = new QComboBox(tours);
    comboWidgets->addItem("Narvolt");
    comboWidgets->addItem("Marteau");
    comboWidgets->addItem("Clou");
    le1 = new QSpinBox();
    le2 = new QSpinBox();
    le3 = new QSpinBox();
    le4 = new QSpinBox();
    //organisation
    formulaire->addRow("Type tour", comboWidgets);
    formulaire->addRow("Range", le1);
    formulaire->addRow("Dommage", le2);
    formulaire->addRow("Prix", le3);
    formulaire->addRow("Vitesse attaque", le4);
    //BOUTTON
    valider = new QPushButton("Valider");
    reset = new QPushButton("Reset");

    valider->setFixedSize(70, 30);
    reset->setFixedSize(70, 30);

    layout->addWidget(valider, 1, 1);
    layout->addWidget(reset, 1, 2);

    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valider1()));
    QObject::connect(reset, SIGNAL(clicked()), this, SLOT(reset1()));

    vbox->addLayout(formulaire);
    vbox->addLayout(layout);
    tours->setLayout(vbox);
}

void QtApp7::enemieW() {
    enemies = new QWidget();

    //page enemies
    formulaire = new QFormLayout();
    QGridLayout* layout2 = new QGridLayout();
    QVBoxLayout* vbox2 = new QVBoxLayout();
    comboWidgets = new QComboBox(enemies);
    comboWidgets->addItem("Poisson zombie");
    comboWidgets->addItem("Neuci");
    comboWidgets->addItem("Pieuvre");
    le1 = new QSpinBox();
    le2 = new QSpinBox();
    le3 = new QSpinBox();
    le4 = new QSpinBox();
    //organisation
    formulaire->addRow("Type enemie", comboWidgets);
    formulaire->addRow("Dommage", le1);
    formulaire->addRow("Vitesse", le2);
    formulaire->addRow("Vie", le3);
    formulaire->addRow("Prix", le4);
    //BOUTTON
    valider = new QPushButton("Valider");
    reset = new QPushButton("Reset");

    valider->setFixedSize(70, 30);
    reset->setFixedSize(70, 30);

    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valider2()));
    QObject::connect(reset, SIGNAL(clicked()), this, SLOT(reset2()));

    layout2->addWidget(valider, 1, 1);
    layout2->addWidget(reset, 1, 2);

    vbox2->addLayout(formulaire);
    vbox2->addLayout(layout2);
    enemies->setLayout(vbox2);
}

void QtApp7::joueurW() {
    Joueur = new QWidget();

    //page joueur
    formulaire = new QFormLayout();
    QGridLayout* layout2 = new QGridLayout();
    QVBoxLayout* vbox2 = new QVBoxLayout();
    le1 = new QSpinBox();
    le2 = new QSpinBox();
    le3 = new QSpinBox();
    //organisation
    formulaire->addRow("Vie", le1);
    formulaire->addRow("Dommage", le2);
    formulaire->addRow("Range", le3);
    //BOUTTON
    valider = new QPushButton("Valider");
    reset = new QPushButton("Reset");

    valider->setFixedSize(70, 30);
    reset->setFixedSize(70, 30);

    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valider2()));
    QObject::connect(reset, SIGNAL(clicked()), this, SLOT(reset2()));

    layout2->addWidget(valider, 1, 1);
    layout2->addWidget(reset, 1, 2);

    vbox2->addLayout(formulaire);
    vbox2->addLayout(layout2);
    Joueur->setLayout(vbox2);
}

QTabWidget* QtApp7::Tours() {
    onglets = new QTabWidget(this);
    onglets->setGeometry(30, 20, 240, 160);

    enemieW();
    tourW();
    joueurW();

    onglets->addTab(tours, "Tours");
    onglets->addTab(enemies, "Enemies");
    onglets->addTab(Joueur, "Joueurs");
    return onglets;
}

QLayout* QtApp7::enemie() {
    QGridLayout* layout = new QGridLayout();
    valider = new QPushButton("Ok");
    reset = new QPushButton("Annuler");
    layout->addWidget(valider, 1, 1);
    layout->addWidget(reset, 1, 2);

    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(soummission()));
    QObject::connect(reset, SIGNAL(clicked()), qApp, SLOT(quit()));
    return layout;
}

//definition des slots
void QtApp7::reset1() {
    le1->setValue(0);
    le2->setValue(0);
}

void QtApp7::reset2() {
    le1->setValue(0);
    le2->setValue(0);
    le3->setValue(0);
}

bool QtApp7::verification1() {
    QString typeTour;
    int  range, dommage;
    typeTour = comboWidgets->currentText();
    range = le1->value();
    dommage = le2->value();
    if (range > 0 || dommage > 0) {
        return false;
    }
    else {
        return true;
    }
}

void QtApp7::valider1() {
    QString typeTour;
    int  range, dommage;
    typeTour = comboWidgets->currentText();
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
    typeEnemie = comboWidgets->currentText();

    dommage = le1->value();
    vitesse = le2->value();
    vie = le3->value();

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
    typeEnemie = comboWidgets->currentText();

    dommage = le1->value();
    vitesse = le2->value();
    vie = le3->value();

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
