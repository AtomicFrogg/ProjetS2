#include "Musique.h"

Musique::Musique(const string& cheminDossier, string nomFichier, const bool loop)
{
	this->cheminDossier = cheminDossier;
	this->nomFichier = nomFichier;
	this->loop = loop;
}

Musique::~Musique() = default;

void Musique::setCheminDossier(const string& chemin)
{
	this->cheminDossier = chemin;
}

void Musique::changerMusique(const string& nomFichier)
{
	this->nomFichier = nomFichier;
	this->play();
}

string Musique::getNomFichier()
{
	return this->nomFichier;
}


void Musique::play() const
{
	string nomComplet = this->cheminDossier + this->nomFichier;
	wstring wFilename(nomComplet.begin(), nomComplet.end());

	if (this->loop)
	{
		
		PlaySound(wFilename.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else
	{
		PlaySound(wFilename.c_str(), NULL, SND_FILENAME | SND_ASYNC);
	}

}

void Musique::stop() const
{
	PlaySound(nullptr, nullptr, 0);
}



void Musique::toggleLoop()
{
	this->loop = !this->loop;
}






std::string Musique::getExecutablePath() {
	char path[MAX_PATH]; // Buffer pour stocker le chemin
	GetModuleFileNameA(NULL, path, MAX_PATH); // Récupère le chemin de l'exécutable
	return std::string(path);
}
