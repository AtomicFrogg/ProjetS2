TEMPLATE     = vcapp
TARGET       = GameTD
CONFIG      += warn_on qt debug windows console
HEADERS     += Jeu\Header\Carte.h Tours\Header\Defenseur.h Jeu\Header\dimension.h Ennemis\Header\Ennemie.h Ennemis\Header\EnsembleEnnemie.h Tours\Header\EnsembleTour.h Jeu\Header\Joueur.h Jeu\Header\test.h Tours\Header\Tour.h Tours\Header\TourBase1.h Tours\Header\Narvolt.h Tours\Header\Canonnier.h Jeu\Header\Input.h Jeu\Header\GUI.h Jeu\Header\Donnees.h includeJson/serial/SerialPort.hpp includeJson/json.hpp Interface\Header\Interface.h Interface\Header\Case.h
SOURCES     += Jeu\Code\Carte.cpp Tours\Code\Defenseur.cpp Ennemis\Code\Ennemie.cpp Ennemis\Code\EnsembleEnnemie.cpp Tours\Code\EnsembleTour.cpp Jeu\Code\GameTD.cpp Jeu\Code\Joueur.cpp Jeu\Code\test.cpp Tours\Code\Tour.cpp Tours\Code\TourBase1.cpp Tours\Code\Narvolt.cpp Tours\Code\Canonnier.cpp Jeu\Code\Input.cpp Jeu\Code\GUI.cpp includeJson\serial\SerialPort.cpp Interface\code\Interface.cpp Interface\code\Case.cpp
INCLUDEPATH +=
LIBS        += 
QT          += widgets
