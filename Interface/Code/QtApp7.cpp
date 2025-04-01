#include "../QtApp7.h"

QtApp7::QtApp7() : QMainWindow()
{
    this->setFixedSize(600, 600);
    QMenu* menuFichier = menuBar()->addMenu("&Fichier");

    QAction* actionOuvrir = new QAction("&Ouvrir", this);
    QAction* actionSauvegarder = new QAction("&Sauvegarder", this);
    QAction* actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionOuvrir);
    menuFichier->addAction(actionSauvegarder);
    menuFichier->addAction(actionQuitter);

    QMenu* menuTower = menuBar()->addMenu("&TowerDefense");

    QAction* actionStatistique = new QAction("&Statistique", this);
    menuTower->addAction(actionStatistique);

    QWidget* zoneCentrale = new QWidget();
    QVBoxLayout* vil = new QVBoxLayout();
    vil->addLayout(outilJeu());
    vil->addWidget(Tours());
    vil->addLayout(validation());
    zoneCentrale->setLayout(vil);
    setCentralWidget(zoneCentrale);
}

QLayout* QtApp7::outilJeu() {
    QGroupBox* outilJeu = new QGroupBox("instrument", this);
    QGridLayout* layout = new QGridLayout();

    QRadioButton* manette = new QRadioButton("manette");
    QRadioButton* clavier = new QRadioButton("clavier");
    manette->setChecked(true);

    QPushButton* valider = new QPushButton("valider");
    valider->setFixedSize(70, 30);
    QVBoxLayout* verticale = new QVBoxLayout;
    verticale->addWidget(manette);
    verticale->addWidget(clavier);
    verticale->addWidget(valider);
   
    outilJeu->setGeometry(300, 300, 150, 150);
    outilJeu->setLayout(verticale);
    layout->addWidget(outilJeu, 0, 0);
    return layout;
}

QTabWidget* QtApp7::Tours() {
    QGridLayout* layout = new QGridLayout();
    QVBoxLayout* vbox = new QVBoxLayout();
    QFormLayout* formulaire = new QFormLayout();
    
    QTabWidget* onglets = new QTabWidget(this);
    onglets->setGeometry(30, 20, 240, 160);

    QWidget* tours = new QWidget();
    QWidget* enemies = new QWidget();

    //page tours
    QComboBox* comboTours = new QComboBox(tours);
    comboTours->addItem("Narvolt");
    comboTours->addItem("Marteau");
    comboTours->addItem("Clou");
    QLineEdit* le1 = new QLineEdit();
    QLineEdit* le2 = new QLineEdit();
    //organisation
    formulaire->addRow("Type Tour", comboTours);
    formulaire->addRow("Range", le1);
    formulaire->addRow("Damage", le2);
    //BOUTTON
    QPushButton* valider = new QPushButton("valider");
    QPushButton* annuler = new QPushButton("reset");

    valider->setFixedSize(70, 30);
    annuler->setFixedSize(70, 30);

    layout->addWidget(valider, 1, 1);
    layout->addWidget(annuler, 1, 2);

    vbox->addLayout(formulaire);
    vbox->addLayout(layout);
    tours->setLayout(vbox);


    //page enemies
    QFormLayout* formulaire2 = new QFormLayout();
    QGridLayout* layout2 = new QGridLayout();
    QVBoxLayout* vbox2 = new QVBoxLayout();
    QComboBox* comboenemie = new QComboBox(enemies);
    comboenemie->addItem("Poisson zombie");
    comboenemie->addItem("Neuci");
    comboenemie->addItem("Pieuvre");
    QLineEdit* le12 = new QLineEdit();
    QLineEdit* le13 = new QLineEdit();
    QLineEdit* le14 = new QLineEdit();
    //organisation
    formulaire2->addRow("Type Enemie", comboenemie);
    formulaire2->addRow("Dommage", le12);
    formulaire2->addRow("vitesse", le13);
    formulaire2->addRow("vie", le14);
    //BOUTTON
    QPushButton* validation = new QPushButton("valider");
    QPushButton* annulation = new QPushButton("reset");

    validation->setFixedSize(70, 30);
    annulation->setFixedSize(70, 30);

    layout2->addWidget(valider, 1, 1);
    layout2->addWidget(annuler, 1, 2);

    vbox2->addLayout(formulaire2);
    vbox2->addLayout(layout2);
    enemies->setLayout(vbox2);

    onglets->addTab(tours, "Tours");
    onglets->addTab(enemies, "Enemies");
    return onglets;
}

QLayout* QtApp7::validation() {
    QGridLayout* layout = new QGridLayout();
    QPushButton* ok = new QPushButton("Ok");
    QPushButton* annuler = new QPushButton("Annuler");
    layout->addWidget(ok, 1, 1);
    layout->addWidget(annuler, 1, 2);
    return layout;
}

QtApp7::~QtApp7()
{}
