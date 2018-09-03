#include "PoligonoIrreg.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool PoligonoIrreg::wayToSort(Coordenada i, Coordenada j) { 
        return i.obtenerX() > i.obtenerX();
}

int PoligonoIrreg:: numVertices = 0;

PoligonoIrreg::PoligonoIrreg(int size){
    v.reserve(size);
    cout << "Imprime "<< v.size()<< size<<endl ;
}
void PoligonoIrreg::addVertice(Coordenada c,int indice) {
    numVertices = numVertices + 1;
    v[indice] = c;

 }
int PoligonoIrreg::getNum(){
    return numVertices;
}
void PoligonoIrreg::imprimeVertices() {
    
    cout << "Imprime "<< v.size()<<endl ;
    for(int i = 0; i < v.size(); i++)
    {
        Coordenada a = v[i];
        cout << "Vertice " << i << ": x =" <<  a.obtenerX()  << "  y = " << a.obtenerY() <<endl;
    }
 }
 void PoligonoIrreg::ordenaA(){
     sort(v.begin(),v.end(),wayToSort);

 }