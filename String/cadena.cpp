#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
using namespace std;

 int main(){
    int num_cadenas = 175760;
    int position = 0;
    char *cadena_f = NULL;
    cadena_f = (char*)malloc(num_cadenas*4*sizeof(char));
    for(int i = 0; i < num_cadenas; i++){
        char cadena[4];
        for(int j = 0;j<=3; j++)
        {
            cadena[j] = rand()%(90-65 + 1) + 65;
        }
        cadena[3] = ' ';
        memcpy(cadena_f + position, cadena, 4);
        position = position + 4;
    }     
    char *tmp;
    int count=0;  
    for(int i = 0; cadena_f[i]; i++)
    {
        
        if (cadena_f[i]=='I') {
            
            if (cadena_f[i+1]=='P') {
                
                
                if (cadena_f[i+2]=='N') {
                    count++;
                    continue;
                }
                
            }
            
        }
    }
  
    free(cadena_f);
    cout << count << endl;
    
 }
 