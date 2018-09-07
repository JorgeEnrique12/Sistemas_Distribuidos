 #include <iostream>  
 #include <cmath>
 #include <iomanip>
 using namespace std; 
 const double PI = acos(-1.0); 
 class Circulo
{
  private:
    double radio;
 public:
 Circulo(double = 1.0);
 double calcval();
 };

 Circulo::Circulo(double r) : radio(r)
 { }

 double Circulo::calcval()  {
 return(PI * radio * radio);
 }

 class Cilindro : public Circulo
 {
 private:
 double longitud;
 public:
 Cilindro(double r = 1.0, double l = 1.0) : Circulo(r), longitud(l) {}
 double calcval();
 };

 double Cilindro::calcval()  {
 return (longitud * Circulo::calcval());
 }

 class Toroide : public Cilindro
 {
     public:
     Toroide(double r = 1.0 ,double l = 1.0) : Cilindro(r,l) {}
     void printData();
 };

void Toroide::printData(){
    cout << "Toroide: " << Cilindro::calcval() << endl;

}
  int main()
 {
 Circulo Circulo_1, Circulo_2(2);
 Cilindro Cilindro_1(3,4);
 Toroide t(3,4);

 cout << "El área de Circulo_1 es " << Circulo_1.calcval() << endl;
 cout << "El área de Circulo_2 es " << Circulo_2.calcval() << endl;
 cout << "El volumen de Cilindro_1 es " << Cilindro_1.calcval() << endl;
 Circulo_1 = Cilindro_1;
 cout << "\nEl área de Circulo_1 es ahora " << Circulo_1.calcval() << endl;
 cout <<"PI : "<<  setprecision(40) << PI << endl;
 t.printData();
 cout << t.calcval() << endl;
 return 0;
 }
