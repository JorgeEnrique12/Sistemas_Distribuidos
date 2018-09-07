#include "PoligonoIrreg.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool PoligonoIrreg::sort1(Coordenada i, Coordenada j) { 
        return i.getMagnitud() < j.getMagnitud();
}

int PoligonoIrreg:: numVertices = 0;
PoligonoIrreg::PoligonoIrreg(int size){
    v.reserve(size);
}
PoligonoIrreg::~PoligonoIrreg(){}

void PoligonoIrreg::addVertice(Coordenada c,int indice) {
    numVertices = numVertices + 1;
    v.push_back(c);

 }

int PoligonoIrreg::getNum(){
    return numVertices;
}
void PoligonoIrreg::imprimeVertices() {
    for(int i = 0; i < v.size(); i++)
    {   
        
        Coordenada a = v[i];
        cout << "Vertice " << i << ": x=" <<  a.obtenerX()  << "y = " << a.obtenerY() <<"  Magnitud:  "<< a.getMagnitud()<<endl;
    }
    
 }

void PoligonoIrreg::ordenaA(){
    sort(v.begin(),v.end(),sort1);
}

Coordenada PoligonoIrreg::getVertice(int n){
    return v[n];
}