GameTD:GameTD.o Ennemie.o Tour.o EnsembleEnnemie.o EnsembleTour.o Carte.o test.o
	g++ -o GameTD GameTD.o Ennemie.o Tour.o EnsembleEnnemie.o EnsembleTour.o Carte.o test.o
	
GameTD.o:GameTD.cpp test.h Carte.h EnsembleEnnemie.h Ennemie.h EnsembleTour.h Tour.h dimension.h
	g++ -g -c GameTD.cpp
	
Ennemie.o:Ennemie.cpp Ennemie.h 
	g++ -g -c Ennemie.cpp
	
Tour.o:Tour.cpp Tour.h dimension.h
	g++ -g -c Tour.cpp
	
EnsembleEnnemie.o: EnsembleEnnemie.cpp EnsembleEnnemie.h Ennemie.h
	g++ -g -c EnsembleEnnemie.cpp

EnsembleTour.0: EnsembleTour.cpp EnsembleTour.h Tour.h dimension.h
	g++ -g -c EnsembleTour.cpp
	
	
Carte.o: Carte.cpp Carte.h EnsembleEnnemie.h Ennemie.h EnsembleTour.h Tour.h dimension.h
	g++ -g -c Carte.cpp
	
test.o: test.cpp test.h Carte.h EnsembleEnnemie.h Ennemie.h EnsembleTour.h Tour.h dimension.h
	g++ -g -c test.cpp

clean:
	rm -f *.o
