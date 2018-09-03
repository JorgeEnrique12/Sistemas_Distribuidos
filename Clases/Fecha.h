#ifndef FECHA_H_
#define FECHA_H_

class Fecha {
private:
   int dia;
   int mes;
   int anio;
   int matriz[500][5]; 
public:
Fecha(int = 3, int = 4, int = 2014); 
void inicializaFecha(int, int, int); 
void muestraFecha();
int convierte();

}; 

#endif