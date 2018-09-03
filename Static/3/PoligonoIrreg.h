#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>
#include "Coordenada.h"
using namespace std;



class PoligonoIrreg {
private:
double x;
double y;
vector <Coordenada> v;
static int getVertices();
public:
    PoligonoIrreg(int size);
    void addVertice(Coordenada c);
    void imprimeVertices();
 };

 #endif