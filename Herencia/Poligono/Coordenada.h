#ifndef COORDENADA_H_
#define COORDENADA_H_


class Coordenada {
private:
long double x;
long double y;
long double magnitud;
public:
    Coordenada(long double = 0, long double = 0,long double = 0);
    long double obtenerX();
    long double obtenerY();
    long double getMagnitud();
 };

 #endif