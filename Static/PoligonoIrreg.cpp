#include "PoligonoIrreg.h"
#include <iostream>
using namespace std;


int PoligonoIrreg:: numVertices = 0;
PoligonoIrreg::PoligonoIrreg(int size){
    v.reserve(size);
}
PoligonoIrreg::~PoligonoIrreg(){}
void PoligonoIrreg::addVertice(Coordenada c,int indice) {
    numVertices = numVertices + 1;
    v[indice] = c;

 }

int PoligonoIrreg::getNum(){
    return numVertices;
}
void PoligonoIrreg::imprimeVertices() {
    
    for(int i = 0; i < v.size(); i++)
    {
        Coordenada a = v[i];
        cout << "Vertice " << i << ": x=" <<  a.obtenerX()  << "y = " << a.obtenerY() <<endl;
    }
    
 }