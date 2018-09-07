main: main.cpp PoligonoReg.o PoligonoIrreg.o Coordenada.o
	g++ main.cpp PoligonoReg.o PoligonoIrreg.o Coordenada.o -o main
PoligonoReg.o : PoligonoIrreg.cpp  PoligonoIrreg.o  PoligonoReg.h 
	g++ PoligonoReg.cpp  -c
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h 
	g++ PoligonoIrreg.cpp  -c
Coordenada.o: Coordenada.cpp Coordenada.h 
	g++ Coordenada.cpp -c