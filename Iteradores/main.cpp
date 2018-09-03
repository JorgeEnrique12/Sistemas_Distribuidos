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
    PoligonoIrreg1.addVertice(Coordenada(rand()%30+1,rand()%30+1),0);
    PoligonoIrreg1.imprimeVertices();
    cout << "Imprimiendo..." <<endl;
    


    return 0;
 }