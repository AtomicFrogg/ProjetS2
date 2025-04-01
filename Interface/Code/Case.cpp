#include "../Header/Case.h"

Case::Case(QWidget *parent, int t, GUI* g, int posi, int posj):QLabel(parent)
{
	type = t;
	gui = g;
	i = posi;
	j = posj;
	this->setFixedSize(CARRE, CARRE);
	choixBackground(type);
	image = new QLabel(this);
}

Case::~Case()
{

}

void Case::choixBackground(int type)
{
	bool gauche;
	bool droit;
	bool haut;
	bool bas;

	if (j <= 1) gauche = 1;
	else gauche = gui->getDonnees(i, j - 1)->type == 1;
	if (i <= 0) bas = 0;
	else bas = gui->getDonnees(i + 1, j)->type == 1;
	if (i >= HAUTEUR) haut = 0;
	else haut = gui->getDonnees(i - 1, j)->type == 1;
	if (j >= LARGEUR - 2) droit = 1;
	else droit = gui->getDonnees(i, j + 1)->type == 1;
	switch (type)
	{

	case 0:
		this->setPixmap(QPixmap("Images/Grass.png").scaled(CARRE, CARRE));
		break;
	case 1:
		if (haut && bas)
		{
			this->setPixmap(QPixmap("Images/Water1.png").scaled(CARRE, CARRE));
		}
		else if (droit && gauche)
		{
			this->setPixmap(QPixmap("Images/Water.png").scaled(CARRE, CARRE));
		}
		else if (gauche && haut)
		{
			this->setPixmap(QPixmap("Images/WaterCoin4.png").scaled(CARRE, CARRE));
		}
		else if (droit && haut)
		{
			this->setPixmap(QPixmap("Images/WaterCoin1.png").scaled(CARRE, CARRE));
		}
		else if (droit && bas)
		{
			this->setPixmap(QPixmap("Images/WaterCoin2.png").scaled(CARRE, CARRE));
		}
		else if (gauche && bas)
		{
			this->setPixmap(QPixmap("Images/WaterCoin3.png").scaled(CARRE, CARRE));
		}
		break;
	default:
		cout << "NOPE\n";
		break;
	}
}

void Case::ajouterNarvolt()
{
	clearImage();
	image->setPixmap(QPixmap("Images/Narvolt.png").scaled(CARRE, CARRE));
}

void Case::ajouterCanonnier()
{
	clearImage();
	image->setPixmap(QPixmap("Images/Canonnier.png").scaled(CARRE, CARRE));
}

void Case::ajouterSniper()
{
	clearImage();
	image->setPixmap(QPixmap("Images/Sniper.png").scaled(CARRE, CARRE));
}

void Case::ajouterTourBase()
{
	clearImage();
	image->setPixmap(QPixmap("Images/TourBase.png").scaled(CARRE, CARRE));
}

void Case::clearImage()
{
	delete image;
	image = new QLabel(this);
}