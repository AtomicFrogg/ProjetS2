GameTD: GameTD.o Ennemie.o Tour.o EnsembleEnnemie.o EnsembleTour.o Carte.o test.o Defenseur.o 
	g++ -o GameTD GameTD.o Ennemie.o Tour.o EnsembleEnnemie.o EnsembleTour.o Carte.o test.o Defenseur.o
	
GameTD.o: Jeu/Code/GameTD.cpp Jeu/Header/test.h Jeu/Header/Carte.h Ennemis/Header/EnsembleEnnemie.h Ennemis/Header/Ennemie.h Tours/Header/EnsembleTour.h Tours/Header/Tour.h Jeu/Header/dimension.h Tours/Header/Defenseur.h
	g++ -g -c Jeu/Code/GameTD.cpp
	
Ennemie.o: Ennemis/Code/Ennemie.cpp Ennemis/Header/Ennemie.h
	g++ -g -c Ennemis/Code/Ennemie.cpp
	
Tour.o: Tours/Code/Tour.cpp Tours/Header/Tour.h Jeu/Header/dimension.h Tours/Header/Defenseur.h Jeu/Header/Carte.h Ennemis/Header/EnsembleEnnemie.h Ennemis/Header/Ennemie.h Tours/Header/EnsembleTour.h
	g++ -g -c Tours/Code/Tour.cpp
	
EnsembleEnnemie.o: Ennemis/Code/EnsembleEnnemie.cpp Ennemis/Header/EnsembleEnnemie.h Ennemis/Header/Ennemie.h
	g++ -g -c Ennemis/Code/EnsembleEnnemie.cpp

EnsembleTour.0: Tours/Code/EnsembleTour.cpp Tours/Header/EnsembleTour.h Tours/Header/Tour.h Jeu/Header/dimension.h  Tours/Header/Defenseur.h
	g++ -g -c Tours/Code/EnsembleTour.cpp
	
Carte.o: Jeu/Code/Carte.cpp Jeu/Header/Carte.h Ennemis/Header/EnsembleEnnemie.h Ennemis/HeaderEnnemie.h Tours/Header/EnsembleTour.h Tours/Header/Tour.h Jeu/Header/dimension.h Tours/Header/Defenseur.h
	g++ -g -c Jeu/Code/Carte.cpp
	
test.o: Jeu/Code/test.cpp Jeu/Header/test.h Jeu/Header/Carte.h Ennemis/Header/EnsembleEnnemie.h Ennemis/Header/Ennemie.h Tours/Header/EnsembleTour.h Tours/Header/Tour.h Jeu/Header/dimension.h
	g++ -g -c Jeu/Code/test.cpp

Defenseur.o: Tours/Code/Defenseur.cpp Jeu/Header/dimension.h Tours/Header/Defenseur.h
	g++ -g -c Tours/Code/Defenseur.cpp
	
Joueur.o: Jeu/Code/Joueur.cpp Jeu/Header/Joueur.h Jeu/Header/dimension.h Tours/Header/Defenseur.h
	g++ -g -c Jeu/Code/Joueur.cpp
	
clean:
	rm -f *.o
