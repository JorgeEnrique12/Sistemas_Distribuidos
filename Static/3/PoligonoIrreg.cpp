#include "PoligonoIrreg.h"
#include <iostream>
using namespace std;


PoligonoIrreg::PoligonoIrreg(int size){
    v.reserve(size);
}

void PoligonoIrreg::addVertice(Coordenada c) {
    v.push_back(c);

 }

void PoligonoIrreg::imprimeVertices() {
    
    for(int i = 0; i < v.size(); i++)
    {
        Coordenada a = v[i];
        cout << "Vertice " << i << ": x=" <<  a.obtenerX()  << "y = " << a.obtenerY() <<endl;
    }
    
 }