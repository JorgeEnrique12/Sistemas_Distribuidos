#include "Coordenada.h"
#include <iostream>

Coordenada::Coordenada(long double xx, long double yy,long double mm) : x(xx), y(yy),magnitud(mm) 
{ }

long double Coordenada::obtenerX() {
    return x;
}
long double Coordenada::obtenerY() {
    return y;
}

long double Coordenada::getMagnitud(){
    return magnitud;
}