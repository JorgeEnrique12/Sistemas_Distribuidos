#ifndef POLIGONOREG_H_
#define POLIGONOREG_H_
#include "PoligonoIrreg.h"
#include "PoligonoReg.h"
using namespace std;



class PoligonoReg : public PoligonoIrreg {
private:
long double  angulo;
int numVertices;
public:
    long double obtieneArea();
    PoligonoReg(int v = 1) : PoligonoIrreg(v), numVertices(v),angulo(360.0/v) {}
    void addVertices();
 };

 #endif