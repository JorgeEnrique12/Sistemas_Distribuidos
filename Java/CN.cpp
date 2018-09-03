#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double i=0;
	double Max = 10000000;
	double seno, coseno, tangente, logaritmo, raizCuad;
	while(i<Max)
	{
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log10(i);
		raizCuad += sqrt(i);
		i++;
	}
	return 0;
}