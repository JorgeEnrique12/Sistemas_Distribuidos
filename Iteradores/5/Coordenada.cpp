#include "Coordenada.h"
#include <iostream>

Coordenada::Coordenada(double xx, double yy,double mm) : x(xx), y(yy),magnitud(mm) 
{ }

double Coordenada::obtenerX() {
    return x;
}
double Coordenada::obtenerY() {
    return y;
}

double Coordenada::getMagnitud(){
    return magnitud;
}