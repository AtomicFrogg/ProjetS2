#include "../Header/QtApp7.h"

QtApp7::QtApp7(GUI* g):QMainWindow()
{
    
    gui = g;
    
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
    vil->addLayout(ennemie());
    zoneCentrale->setLayout(vil);
    setCentralWidget(zoneCentrale);
}

QLayout* QtApp7::outilJeu() {
    QGroupBox* outilJeu = new QGroupBox("Peripherique", this);
    QGridLayout* layout = new QGridLayout();

    manette = new QRadioButton("manette");
    clavier = new QRadioButton("clavier");
    clavier->setChecked(true);

    QVBoxLayout* verticale = new QVBoxLayout;
    verticale->addWidget(manette);
    verticale->addWidget(clavier);
   
    outilJeu->setGeometry(300, 300, 150, 150);
    outilJeu->setLayout(verticale);
    layout->addWidget(outilJeu, 0, 0);

    QGroupBox* map = new QGroupBox("Choix de cartes", this);
    carte1 = new QRadioButton("Carte #1");
    carte2 = new QRadioButton("Carte #2");

    carte1->setChecked(true);
    QVBoxLayout* carteV = new QVBoxLayout;
    carteV->addWidget(carte1);
    carteV->addWidget(carte2);


    map->setGeometry(300, 300, 150, 150);
    map->setLayout(carteV);
    layout->addWidget(map, 1, 0);
    


    return layout;
}

void QtApp7::tourW() {
    QGridLayout* layout = new QGridLayout();
    QVBoxLayout* vbox = new QVBoxLayout();
    formulaire = new QFormLayout();
    tours = new QWidget();


    //page tours
    comboTours = new QComboBox(tours);
    comboTours->addItem("Narvolt");
    comboTours->addItem("Canonnier");
    comboTours->addItem("Sniper");
    comboTours->addItem("Tour de base");
    le1 = new QSpinBox();
    le2 = new QSpinBox();
    le3 = new QSpinBox();
    le4 = new QSpinBox();

    //definition de la taille des spinBox
    le1->setMaximum(9999);
    le2->setMaximum(9999);
    le3->setMaximum(9999);
    le4->setMaximum(9999);
    //organisation
    formulaire->addRow("Type tour", comboTours);
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

void QtApp7::ennemieW() {
    ennemies = new QWidget();

    //page ennemies
    formulaire = new QFormLayout();
    QGridLayout* layout2 = new QGridLayout();
    QVBoxLayout* vbox2 = new QVBoxLayout();
    comboennemie = new QComboBox(ennemies);
    comboennemie->addItem("Requin");
    comboennemie->addItem("Saumon");
    comboennemie->addItem("Baleine");
    le11 = new QSpinBox();
    le12 = new QSpinBox();
    le13 = new QSpinBox();
    le14 = new QSpinBox();
    //definition de la taille des spinBox
    le11->setMaximum(9999);
    le12->setMaximum(9999);
    le13->setMaximum(9999);
    le14->setMaximum(9999);
    //organisation
    formulaire->addRow("Type ennemie", comboennemie);
    formulaire->addRow("Dommage", le11);
    formulaire->addRow("Vitesse", le12);
    formulaire->addRow("Vie", le13);
    formulaire->addRow("Revenu", le14);
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
    ennemies->setLayout(vbox2);
}

void QtApp7::joueurW() {
    Joueur = new QWidget();

    //page joueur
    formulaire = new QFormLayout();
    QGridLayout* layout2 = new QGridLayout();
    QVBoxLayout* vbox2 = new QVBoxLayout();
    le21 = new QSpinBox();
    le22 = new QSpinBox();
    le23 = new QSpinBox();
    le24 = new QSpinBox();
    //definition de la taille des spinBox
    le21->setMaximum(9999);
    le22->setMaximum(9999);
    le23->setMaximum(9999);
    le24->setMaximum(9999);
    //organisation
    formulaire->addRow("Vie", le21);
    formulaire->addRow("Dommage", le22);
    formulaire->addRow("Range", le23);
    formulaire->addRow("Argent", le24);
    //BOUTTON
    valider = new QPushButton("Valider");
    reset = new QPushButton("Reset");

    valider->setFixedSize(70, 30);
    reset->setFixedSize(70, 30);

    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valider3()));
    QObject::connect(reset, SIGNAL(clicked()), this, SLOT(reset3()));

    layout2->addWidget(valider, 1, 1);
    layout2->addWidget(reset, 1, 2);

    vbox2->addLayout(formulaire);
    vbox2->addLayout(layout2);
    Joueur->setLayout(vbox2);
}

QTabWidget* QtApp7::Tours() {
    onglets = new QTabWidget(this);
    onglets->setGeometry(30, 20, 240, 160);

    ennemieW();
    tourW();
    joueurW();

    onglets->addTab(tours, "Tours");
    onglets->addTab(ennemies, "Enemies");
    onglets->addTab(Joueur, "Joueurs");
    return onglets;
}

QLayout* QtApp7::ennemie() {
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
    gui = new GUI();
    QString typeTour = comboTours->currentText();
    if (typeTour == "Tour de base") {
        le1->setValue(gui->getJoueur()->DonneesTourBase.range);
        le2->setValue(gui->getJoueur()->DonneesTourBase.degat);
        le3->setValue(gui->getJoueur()->DonneesTourBase.prix);
        le4->setValue(gui->getJoueur()->DonneesTourBase.vitesseAttaque);
    }else if (typeTour == "Narvolt") {
        le1->setValue(gui->getJoueur()->DonneesNarvolt.range);
        le2->setValue(gui->getJoueur()->DonneesNarvolt.degat);
        le3->setValue(gui->getJoueur()->DonneesNarvolt.prix);
        le4->setValue(gui->getJoueur()->DonneesNarvolt.vitesseAttaque);
    }else if (typeTour == "Canonnier") {
        le1->setValue(gui->getJoueur()->DonneesCanonnier.range);
        le2->setValue(gui->getJoueur()->DonneesCanonnier.degat);
        le3->setValue(gui->getJoueur()->DonneesCanonnier.prix);
        le4->setValue(gui->getJoueur()->DonneesCanonnier.vitesseAttaque);
    }
    else {
        le1->setValue(gui->getJoueur()->DonneesSniper.range);
        le2->setValue(gui->getJoueur()->DonneesSniper.degat);
        le3->setValue(gui->getJoueur()->DonneesSniper.prix);
        le4->setValue(gui->getJoueur()->DonneesSniper.vitesseAttaque);
    }
    
}

void QtApp7::reset2() {
    gui = new GUI();
    QString typeTour = comboennemie->currentText();
    if (typeTour == "Requin") {
        le11->setValue(gui->getCarte()->Requin.degat);
        le12->setValue(gui->getCarte()->Requin.vitesse);
        le13->setValue(gui->getCarte()->Requin.vie);
        le14->setValue(gui->getCarte()->Requin.revenu);
    }
    else if (typeTour == "Saumon") {
        le11->setValue(gui->getCarte()->Saumon.degat);
        le12->setValue(gui->getCarte()->Saumon.vitesse);
        le13->setValue(gui->getCarte()->Saumon.vie);
        le14->setValue(gui->getCarte()->Saumon.revenu);
    }
    else {
        le11->setValue(gui->getCarte()->Baleine.degat);
        le12->setValue(gui->getCarte()->Baleine.vitesse);
        le13->setValue(gui->getCarte()->Baleine.vie);
        le14->setValue(gui->getCarte()->Baleine.revenu);
    }
}

void QtApp7::reset3()
{
    gui = new GUI();
    le21->setValue(gui->getCarte()->getVie());
    le22->setValue(gui->getJoueur()->getDegat());
    le23->setValue(gui->getJoueur()->getRange());
    le24->setValue(gui->getCarte()->getArgent());
}

bool QtApp7::verification1() {
    QString typeTour;
    int  range, dommage,prix,vitesseAttaque;
    typeTour = comboTours->currentText();
    range = le1->value();
    dommage = le2->value();
    prix = le3->value();
    vitesseAttaque = le4->value();

    if (range <= 0 || dommage <= 0 || prix < 0 || vitesseAttaque <= 0) {
        return false;
    }
    else {
        return true;
    }
}

void QtApp7::valider1() {
    QString typeTour;
    int  range, dommage,prix,vitesseAttaque;
    typeTour = comboTours->currentText();
    range = le1->value();
    dommage = le2->value();
    vitesseAttaque = le4->value();
    prix = le3->value();

    if (!verification1()) {
        QMessageBox::warning(this, "Information Tour", "Ces valeurs sont trop basses pour debuter le jeu!!!");
    }
    else {
        QMessageBox::information(this, "Information Tour", QString("Type Tour:%1<br/>").arg(typeTour) + QString("range:%1<br/>").arg(range) + QString("dommage:%1<br/>").arg(dommage));
        if (typeTour == "Tour de base")
        {
            gui->getJoueur()->DonneesTourBase.degat = dommage;
            gui->getJoueur()->DonneesTourBase.prix = prix;
            gui->getJoueur()->DonneesTourBase.range = range;
            gui->getJoueur()->DonneesTourBase.vitesseAttaque = vitesseAttaque;
        }else if (typeTour == "Narvolt")
        {
            gui->getJoueur()->DonneesNarvolt.degat = dommage;
            gui->getJoueur()->DonneesNarvolt.prix = prix;
            gui->getJoueur()->DonneesNarvolt.range = range;
            gui->getJoueur()->DonneesNarvolt.vitesseAttaque = vitesseAttaque;
        }else if (typeTour == "Canonnier")
        {
            gui->getJoueur()->DonneesCanonnier.degat = dommage;
            gui->getJoueur()->DonneesCanonnier.prix = prix;
            gui->getJoueur()->DonneesCanonnier.range = range;
            gui->getJoueur()->DonneesCanonnier.vitesseAttaque = vitesseAttaque;
        }else if (typeTour == "Sniper")
        {
            gui->getJoueur()->DonneesSniper.degat = dommage;
            gui->getJoueur()->DonneesSniper.prix = prix;
            gui->getJoueur()->DonneesSniper.range = range;
            gui->getJoueur()->DonneesSniper.vitesseAttaque = vitesseAttaque;
        }
        cout << gui->getJoueur()->DonneesNarvolt.range << "\n";
        cout << gui->getJoueur()->DonneesNarvolt.degat<<"\n";
        cout << gui->getJoueur()->DonneesNarvolt.prix << "\n";
        cout << gui->getJoueur()->DonneesNarvolt.vitesseAttaque << "\n";
    }
}

bool QtApp7::verification2() {
    QString typeEnemie;
    result = false;
    int  vitesse, vie, dommage,revenu;
    typeEnemie = comboennemie->currentText();

    dommage = le11->value();
    vitesse = le12->value();
    vie = le13->value();
    revenu = le14->value();

    if (dommage < 1 || vitesse < 1 || vie < 1 || revenu < 0) {
        return false;
    }
    else {
        return true;
    }
}

void QtApp7::valider2() {
    QString typeEnemie;
    int  vitesse, vie, dommage,revenu;
    typeEnemie = comboennemie->currentText();

    dommage = le11->value();
    vitesse = le12->value();
    vie = le13->value();
    revenu = le14->value();

    if (!verification2()) {
        QMessageBox::warning(this, "Information Enemie", "Ces valeurs sont trop basses pour debuter le jeu!!!");
    }
    else {
        QMessageBox::information(this, "Information Enemie", QString("Type Enemie:%1<br/>").arg(typeEnemie) + QString("dommage:%1<br/>").arg(dommage) + QString("vitesse:%1<br/>").arg(vitesse) + QString("vie:%1<br/>").arg(vie));
        if (typeEnemie == "Baleine")
        {
            gui->getCarte()->Baleine.vie = vie;
            gui->getCarte()->Baleine.degat = dommage;
            gui->getCarte()->Baleine.revenu = revenu;
            gui->getCarte()->Baleine.vitesse = vitesse;
        }else if (typeEnemie == "Requin")
        {
            gui->getCarte()->Requin.vie = vie;
            gui->getCarte()->Requin.degat = dommage;
            gui->getCarte()->Requin.revenu = revenu;
            gui->getCarte()->Requin.vitesse = vitesse;
        }else if (typeEnemie == "Saumon")
        {
            gui->getCarte()->Saumon.vie = vie;
            gui->getCarte()->Saumon.degat = dommage;
            gui->getCarte()->Saumon.revenu = revenu;
            gui->getCarte()->Saumon.vitesse = vitesse;
        }
        else {
            QMessageBox::critical(this, "Erreur","Erreur selection ennemie");
        }
        cout << gui->getCarte()->Requin.degat<< "\n";
        cout << gui->getCarte()->Requin.vitesse<< "\n";
        cout << gui->getCarte()->Requin.vie<< "\n";
        cout << gui->getCarte()->Requin.revenu<< "\n";
    }
}

void QtApp7::valider3() {
    int  range, dommage, vie, argent;
    vie = le21->value();
    dommage = le22->value();
    range = le23->value();
    argent = le24->value();



    if (!verification3()) {
        QMessageBox::warning(this, "Information Tour", "Ces valeurs sont trop basses pour debuter le jeu!!!");
    }
    else {
        QMessageBox::information(this, "Information Tour", QString("range:%1<br/>").arg(range) + QString("dommage:%1<br/>").arg(dommage));

        gui->getJoueur()->setDegat(dommage);
        gui->getJoueur()->setRange(range);
        gui->getCarte()->setVie(vie);
        gui->getCarte()->setArgent(argent);

        //cout << gui->getJoueur()->getDegat() << endl;
        //cout << gui->getJoueur()->getRange() << endl;
        //cout << gui->getCarte()->getVie() << endl;
        //cout << gui->getCarte()->getArgent() << endl;
    }
}

bool QtApp7::verification3()
{
    int vie, dommage, range, argent;

    vie = le21->value();
    dommage = le22->value();
    range = le23->value();
    argent = le24->value();

    if (dommage < 1 || vie < 1 || range < 1 || argent < 1) {
        return false;
    }
    else {
        return true;
    }
}


void QtApp7::soummission(){
   
    if (manette->isChecked()) {
        //QMessageBox::information(this, "Information Generale", "Vous avez choisir la <strong>manette</strong> pour le jeu!!!");
        gui->setManette(true);
    }
    else {
        //QMessageBox::information(this, "Information Generale", "Vous avez choisir le <strong>clavier</strong> pour le jeu!!!");
        gui->setManette(false);
    }
    if (carte1->isChecked()){
        gui->setNumCarte(1);
        //QMessageBox::information(this, "Information Generale", "Vous avez choisir la <strong>carte 1</strong> pour le jeu!!!");
    }
    else if (carte2->isChecked())
    {
        gui->setNumCarte(2);
        //QMessageBox::information(this, "Information Generale", "Vous avez choisir la <strong>carte 2</strong> pour le jeu!!!");
    }
    int num = gui->getNumCarte();
    gui->chooseMap(num);
    jeu = new Interface(gui);
    jeu->move(0, 0);
    jeu->show();
    Musique* son = new Musique("Muse/Sons/", "MainTheme.wav", true);
    son->play();
    this->close();
}

QtApp7::~QtApp7()
{}


Interface* QtApp7::getInterface()
{
    return jeu;
}

void QtApp7::valeurInitialeTour(GUI* c)
{

}