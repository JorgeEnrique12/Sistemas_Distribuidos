#include "Coordenada.h"
#include <iostream>
#include <math.h>

 Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)  
 { }

 double Coordenada::obtenerX() {
    return x;
 }
double Coordenada::obtenerY() {
    return y;
 }
 void Coordenada::convertir(){
     x = r*cos(angle);
     y = r*sin(angle);
 }