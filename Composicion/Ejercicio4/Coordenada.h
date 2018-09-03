#ifndef COORDENADA_H_
#define COORDENADA_H_


class Coordenada {
private:
double x;
double y;
double r;
double angle;
public:
    Coordenada(double = 0, double = 0);
    double obtenerX();
    double obtenerY();
    void convertir();
 };

 #endif