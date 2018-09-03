#include "Fecha.h"
#include <iostream>
using namespace std;

int masVieja(Fecha fecha1, Fecha fecha2){
    int f1 = fecha1.convierte();
    int f2 = fecha2.convierte();
    if (f1 < f2) {
        return 1;
    }   
    if (f1>f2) {
        return -1;
    }
    return 0;
}

int masVieja2(Fecha& fecha1, Fecha &fecha2){
    int f1 = fecha1.convierte();
    int f2 = fecha2.convierte();
    if (f1 < f2) {
        return 1;
    }   
    if (f1>f2) {
        return -1;
    }
    return 0;
}

int main(){
    Fecha a,b;
    double time1;

    for(long int i = 0; i < 10000000; i++)
    {
        a.inicializaFecha(rand() % 31 + 1,rand() % 12 + 1,rand() % 2020 + 1);
        b.inicializaFecha(rand() % 31 + 1,rand() % 12 + 1,rand() % 2020 + 1);
        int result = masVieja(a,b);
    }
    cout << time1 << endl;
    return 0;
}