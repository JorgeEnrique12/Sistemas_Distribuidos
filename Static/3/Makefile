main: main.cpp PoligonoIrreg.o
	g++ main.cpp PoligonoIrreg.o Coordenada.o -o main
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h 
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h 
	g++ Coordenada.cpp -c