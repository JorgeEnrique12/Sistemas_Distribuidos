#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Coordenada.h"
#include "PoligonoIrreg.h"

 using namespace std;

 int main()
 {
     PoligonoIrreg PoligonoIrreg1(10);
     PoligonoIrreg1.addVertice(Coordenada(1,2));
     PoligonoIrreg1.addVertice(Coordenada(3,4));
     PoligonoIrreg1.addVertice(Coordenada(5,6));
     PoligonoIrreg1.addVertice(Coordenada(7,8));
     PoligonoIrreg1.addVertice(Coordenada(9,10));
     PoligonoIrreg1.imprimeVertices();

    return 0;
 }