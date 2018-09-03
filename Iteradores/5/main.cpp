#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "Coordenada.h"
#include "PoligonoIrreg.h"



 using namespace std;

 int main()
 {
        srand(time(NULL));
        int size = 10;
        PoligonoIrreg PoligonoIrreg1(size);
        
        for(int i = 0; i < size; i++)
        {
            double rand1 = ((rand()%20000) - 10000) / (100 + 1.000);
			double rand2 = ((rand()%20000) - 10000) / (100 + 1.000);
            PoligonoIrreg1.addVertice(Coordenada(rand1,rand2, sqrt(pow(rand1,2) + pow(rand2,2))),i);
        }
        PoligonoIrreg1.imprimeVertices();
        PoligonoIrreg1.ordenaA();
        cout << "Ordenada" << endl;
        PoligonoIrreg1.imprimeVertices();
        return 0;
 }
 