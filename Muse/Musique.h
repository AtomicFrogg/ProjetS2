#ifndef MUSIQUE_H
#define MUSIQUE_H

#include <iostream>
#include <fstream>
#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include <mmsystem.h>
#include <QDebug>

using namespace std;


class Musique {
	private:
		string cheminDossier;
		string nomFichier;
		bool loop;

	public:
		/**
		 * Constructeur d'un objet Musique
		 * Format WAV requis
		 * @param cheminDossier Chemin vers le dossier contenant les musiques
		 * @param nomFichier Nom du fichier de la musique
		 * @param loop Si la musique doit jouer en boucle, defaut false
		 */
		Musique(const string& cheminDossier, string nomFichier, bool loop = false);
		~Musique();
		void setCheminDossier(const string& chemin);
		void play() const;
		void stop() const;
		void toggleLoop();
		void changerMusique(const string& nomFichier);
		string getNomFichier();


		static std::string getExecutablePath();

};



#endif //MUSIQUE_H
