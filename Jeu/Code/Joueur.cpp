#include "../Header/Joueur.h"

Joueur::Joueur(int d, float r, int x, int y, int va, Carte* c, string n) :map(c), Defenseur(d, r, x, y, va)
{
	setNom(n);
	DonneesTourBase.degat = 15;
	DonneesTourBase.range = 10;
	DonneesTourBase.prix = 400;
	DonneesTourBase.vitesseAttaque = 5;

	DonneesSniper.degat = 50;
	DonneesSniper.range = 100;
	DonneesSniper.prix = 600;
	DonneesSniper.vitesseAttaque = 10;

	DonneesCanonnier.degat = 25;
	DonneesCanonnier.range = 8;
	DonneesCanonnier.prix = 500;
	DonneesCanonnier.vitesseAttaque = 6;

	DonneesNarvolt.degat = 10;
	DonneesNarvolt.range = 10;
	DonneesNarvolt.prix = 500;
	DonneesNarvolt.vitesseAttaque = 4;
}

Joueur::~Joueur() {
	nom = "";
}

string Joueur::getNom() {
	return nom;
}

void Joueur::setNom(string n) {
	nom = n;
}

Tour* Joueur::ajouterTour(Tour* nouvelleTour)
{
	return tableauTour.ajouterTour(nouvelleTour);
}

bool Joueur::retirerTour(int index)
{
	return tableauTour.retirerTour(index);
}


bool Joueur::reinitialiser()
{
	return tableauTour.reinitialiser();
}

int Joueur::getTaille()
{
	return tableauTour.getTaille();
}

Tour* Joueur::getTour(int index)
{
	return tableauTour.getTour(index);
}

int Joueur::getPrix(int index)
{
	return tableauTour.getPrix(index);
}

void Joueur::setPrix(int index, int p)
{
	tableauTour.setPrix(index, p);
}

int Joueur::getTier(int index)
{
	return tableauTour.getTier(index);
}

void Joueur::setTier(int index, int t)
{
	tableauTour.setTier(index, t);
}

void Joueur::setVitesse(int index, int v)
{
	tableauTour.setVitesse(index, v);
}

int Joueur::getVitesse(int index)
{
	return tableauTour.getVitesse(index);
}

void Joueur::afficherTour(ostream& s)
{
	tableauTour.afficher(s);
}

void Joueur::attaquerJoueur()
{

	if (attaque == true)
	{
		double distance;
		for (int i = 0; i < map->getTailleEnnemie(); i++)
		{
			distance = sqrt(carre(map->getCoordonnee(i).x - this->getPosition().x) + carre(map->getCoordonnee(i).y - this->getPosition().y));
			if (distance < getRange())
			{
				this->attaque = false;
				int vie = (map->getVieEnnemie(i) - getDegat());
				if (getCompteurAttaque() == 1) {
					cout << vie;
					if (vie > 0)
					{
						map->getEnnemie()->getEnnemie(i)->setVie(vie);

						setCompteurAttaque(getVitesseAttaque());
						break;
					}
					else
					{
						map->retirerEnnemie(i);
						break;
					}
				}
				else
				{
					map->retirerEnnemie(i);
					break;
				}
			}
		}
	}
	else
	{
		setCompteurAttaque(getCompteurAttaque() - 1);
		if (getCompteurAttaque() == 0)
		{
			attaque = true;
		}

	}
}

void Joueur::attaquer()
{
	tableauTour.attaquer();
}

Tour* Joueur::ajouterTourBase()
{
	Tour* newTour = new TourBase1(DonneesTourBase.degat, DonneesTourBase.range , this->getPosition().x, this->getPosition().y, DonneesTourBase.vitesseAttaque, DonneesTourBase.prix, 0, map);
	return ajouterTour(newTour);
}

Tour* Joueur::ajouterTourSniper()
{
	Tour* newTour = new TourBase1(DonneesSniper.degat, DonneesSniper.range, this->getPosition().x, this->getPosition().y, DonneesSniper.vitesseAttaque, DonneesSniper.prix, 0, map);
	return ajouterTour(newTour);
}

Tour* Joueur::ajouterTourCanonnier()
{
	Tour* newTour = new Canonnier(DonneesCanonnier.degat, DonneesCanonnier.range, this->getPosition().x, this->getPosition().y, DonneesCanonnier.vitesseAttaque, DonneesCanonnier.prix, 0, map, 1);
	return ajouterTour(newTour);
}

Tour* Joueur::ajouterTourNarvolt()
{
	Tour* newTour = new Narvolt(DonneesNarvolt.degat, DonneesNarvolt.range, this->getPosition().x, this->getPosition().y, DonneesNarvolt.vitesseAttaque, DonneesNarvolt.prix, 0, map, 2, 3);
	return ajouterTour(newTour);
}

bool Joueur::ameliorerRange(int index)
{
	return tableauTour.ameliorerRange(index);
}

bool Joueur::ameliorerDegat(int index)
{
	return tableauTour.ameliorerDegat(index);
}
