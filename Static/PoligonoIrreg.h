#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>
#include "Coordenada.h"
using namespace std;



class PoligonoIrreg {
private:
vector <Coordenada> v;
static int numVertices;
public:
    PoligonoIrreg(int size);
    ~PoligonoIrreg();
     void addVertice(Coordenada c,int indice);
     void imprimeVertices();
    static int getNum();
 };

 #endif