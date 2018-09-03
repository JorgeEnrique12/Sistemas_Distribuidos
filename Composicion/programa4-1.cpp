#include <iostream>
using namespace std; 

class Coordenada {
private:
double x;
double y;
public:
    Coordenada(double = 0, double = 0);
    double obtenerX();
    double obtenerY();
 };

 class Rectangulo
 {
 private:
    Coordenada superiorIzq;
    Coordenada inferiorDer;
 public:
    Rectangulo();
 Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
    void imprimeEsq();
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
    double obtieneArea();
 };

 int main( )
 {
 Rectangulo rectangulo1(2,3,5,1);
    double ancho, alto;

 cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";
 rectangulo1.imprimeEsq();
 double area = rectangulo1.obtieneArea();
 cout << "El área del rectángulo es = " << area << endl;
 return 0;
 }

 Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)  
 { }

 double Coordenada::obtenerX() {
    return x;
 }
double Coordenada::obtenerY() {
    return y;
 }
double Rectangulo::obtieneArea(){
    return (superiorIzq.obtenerY() -   inferiorDer.obtenerY()) * (inferiorDer.obtenerX() -  superiorIzq.obtenerX());
}
Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0){ }
Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer){ }
void Rectangulo::imprimeEsq(){
    cout << "Para la esquina superior izquierda.\n";
    cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina inferior derecha.\n";
    cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
    }
Coordenada Rectangulo::obtieneSupIzq() {
return superiorIzq;
}
Coordenada Rectangulo::obtieneInfDer() {
return inferiorDer;
}