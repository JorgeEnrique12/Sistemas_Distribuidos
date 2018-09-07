#include <iostream>
#include <algorithm>
#include <math.h>
#include "PoligonoReg.h"
#include "PoligonoIrreg.h"
#include "Coordenada.h"



using namespace std;

void PoligonoReg::addVertices(){
    long double angle = 0;
    for(int i = 0; i < numVertices; i++)
    {
        long double x = (long double)cos(angle * M_PI  / 180.0);
        long double y = (long double)sin(angle * M_PI  / 180.0);
        PoligonoIrreg::addVertice(Coordenada(x,y,sqrt(x*x+y*y)),i);
        angle = angle + angulo;
    }
    
}
long double PoligonoReg::obtieneArea(){
    Coordenada Coordena1 = PoligonoIrreg::getVertice(0);
    Coordenada Coordena2 = PoligonoIrreg::getVertice(1);
    long double x = Coordena2.obtenerX() - Coordena1.obtenerX();
    long double y = Coordena2.obtenerY() - Coordena1.obtenerY();
    long double xmedio = (Coordena2.obtenerX() + Coordena1.obtenerX())/2;
    long double ymedio = (Coordena2.obtenerY() + Coordena1.obtenerY())/2;
    long double h = sqrt(xmedio*xmedio + ymedio*ymedio);
    long double base = sqrt(x*x + y*y);
    return numVertices*base*h/2;
}
