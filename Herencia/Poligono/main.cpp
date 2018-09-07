#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "Coordenada.h"
#include "PoligonoReg.h"
#include "PoligonoIrreg.h"
#include <iomanip>      // std::setprecision



 using namespace std;

 int main()
 {

        PoligonoReg PoligonoReg1(1000000);
        PoligonoReg1.addVertices();
        PoligonoReg1.imprimeVertices();
        long double area = PoligonoReg1.obtieneArea();
        cout << setprecision(40) << area <<endl;
 }
 