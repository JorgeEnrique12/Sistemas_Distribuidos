#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "Coordenada.h"
#include "PoligonoIrreg.h"

 using namespace std;

 int main()
 {

        PoligonoIrreg PoligonoIrreg1(20);
        
        for(int i = 0; i < 20; i++)
        {
            PoligonoIrreg1.addVertice(Coordenada(rand()%10 + 1,rand()%10 + 1),i);
        }
        PoligonoIrreg1.imprimeVertices();
        
 }