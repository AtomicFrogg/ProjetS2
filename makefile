GameTD:GameTD.o Ennemie.o Tour.o EnsembleEnnemie.o
	g++ -o GameTD GameTD.o Ennemie.o Tour.o
	
GameTD.o:GameTD.cpp Ennemie.h Tour.h dimension.h
	g++ -g -c GameTD.cpp
	
Ennemie.o:Ennemie.cpp Ennemie.h
	g++ -g -c Ennemie.cpp
	
Tour.o:Tour.cpp Tour.h dimension.h
	g++ -g -c Tour.cpp
	
EnsembleEnnemie.o: EnsembleEnnemie.cpp EnsembleEnnemie.h Ennemie.h
	g++ -g -c EnsembleEnnemie.cpp

clean:
	rm -f *.o
