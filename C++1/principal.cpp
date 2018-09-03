#include "Fecha.h"
using namespace std;

int main(){
    Fecha a,b,c(17,8,2017);
    a.inicializaFecha(11,1,2015);
    b.inicializaFecha(11,12,1997);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();
}
