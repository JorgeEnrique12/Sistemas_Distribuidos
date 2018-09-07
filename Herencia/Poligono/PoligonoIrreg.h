#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>
#include "Coordenada.h"
#include "PoligonoIrreg.h"
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
    static bool sort1(Coordenada i, Coordenada j);
    void ordenaA();
    Coordenada getVertice(int);
 };

 #endif