#include <iostream> 
using namespace std;
class Fecha
{
 private:
 int dia;
 int mes;
 int anio;
 public:
 Fecha(int = 3, int = 4, int = 2014);
 void inicializaFecha(int, int, int);
    void muestraFecha();
    int masVieja(Fecha, Fecha);
 };

 Fecha::Fecha(int dd, int mm, int aaaa)  {
    mes = mm;
    dia = dd;
    anio = aaaa;
 }

 void Fecha::inicializaFecha(int  dd, int mm, int aaaa)  {
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
 }

 void Fecha::muestraFecha()
 {
 cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
 return;
 }

 int Fecha::masVieja(Fecha fecha1, Fecha fecha2){
     
     if(fecha1.anio < fecha2.anio){
         return 1;
     }
     if(fecha1.anio > fecha2.anio){
         return -1;
     }
     
     if (fecha1.anio == fecha2.anio) {
         if(fecha1.mes < fecha2.mes){
             return 1;
        }
        if(fecha1.mes > fecha2.mes){
            return -1;
        }

        if (fecha1.mes == fecha2.mes) {
         if(fecha1.dia < fecha2.dia){
             return 1;
        }
        if(fecha1.dia > fecha2.dia){
            return -1;
        }
        
        if (fecha1.dia == fecha2.dia) {
           return 0;
        }
        
     }
     }
     
 }

 int main()
 {
    Fecha a, b, c(21, 9, 1973);

    b.inicializaFecha(17, 6 , 2000);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();
 
 }