#include "Joueur.h"


Joueur::Joueur(int d, float r, int x, int y, Carte* c, string n):map(c),Defenseur(d,r,x,y)
{
    setNom(n);
}

Joueur::~Joueur(){
    nom = "";
}

string Joueur::getNom(){
    return nom;
}

void Joueur::setNom(string n){
    nom = n;
}

int Joueur::ajouterTour(Tour* nouvelleTour)
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
	
	if(attaque == true)
	{
		double distance;
		for(int i = 0; i < map->getTailleEnnemie(); i++)
		{
			distance = sqrt(carre(map->getCoordonnee(i).x - this->getPosition().x) + carre(map->getCoordonnee(i).y - this->getPosition().y));
			if(distance < getRange())
			{
				this->attaque = false;
				int vie = (map->getVieEnnemie(i) - getDegat());
				if (vie > 0)
				{
					map->setVie(vie);
				
					setCompteurAttaque(getVitesseAttaque());
					break;
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

int Joueur::ajouterTourBase()
{
	Tour* newTour = new TourBase1(10,15,4,this->getPosition().x, this->getPosition().y, 400, 0, map);
	return ajouterTour(newTour);
}

int Joueur::ajouterTourSniper()
{
	Tour* newTour = new TourBase1(50,50, 100, this->getPosition().x, this->getPosition().y, 600, 0, map);
	return ajouterTour(newTour);
}

int Joueur::ajouterTourCanonnier()
{
	Tour* newTour = new Canonnier(20, 25, 3, this->getPosition().x, this->getPosition().y, 500, 0, map, 1);
	return ajouterTour(newTour);
}

int Joueur::ajouterTourNarvolt()
{
	Tour* newTour = new Narvolt(15, 20, 5, this->getPosition().x, this->getPosition().y, 700, 0, map, 5, 5);
	return ajouterTour(newTour);
}
