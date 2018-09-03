#include <iostream>

using namespace std;

int main( )  {


	int n = 2;

	cout << "Resultado: " << n + (++n) << "\n";
 
	double precio = 78.7;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Precio: " << precio << "\n";

	return 0;
}
