#include <iostream>
#ifndef Coordenada_CPP
#define Coordenada_CPP
 using namespace std;

 class Coordenada
 {
 private:
  double x;
  double y;
 public:
  Coordenada(double = 0, double = 0);
  double obtenerX();
  double obtenerY();
 };
 #endif
