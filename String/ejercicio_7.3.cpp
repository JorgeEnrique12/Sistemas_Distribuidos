#include <iostream>
#include <string>

using namespace std;


int main(){

	system("clear");

	int limit = 175760;
	int limPa = 3;

	string c;
	string palabra = "";
//	srand(time(NULL));
	for(int i=0; i<limit; i++){

		for(int j=0; j<limPa; j++){
			c =rand()%(90-65 + 1) + 65;
			palabra.append(c);
		}
		palabra.append(" ");
	}

	int cont = 0;
	for(int i=0; i<palabra.length(); i+=3){
		i = palabra.find("IPN",i);
		if(i == -1)
			break;
		cont++;
	}
	cout << "cont: " << cont << endl;


	cout << endl << endl;

	return 0;
}

