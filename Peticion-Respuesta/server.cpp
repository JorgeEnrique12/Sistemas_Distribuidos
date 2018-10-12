#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "Respuesta.h"
using namespace std;
#define ordenaCadena 1;


void inverse(char cadena[],char output[]){
    bzero(output, 4000);
    char aux[100];
    int size = strlen(cadena);
    int s = 0;
    int last = 0;
    for(int i = size-1; i!=-1; i--){
        if(*(cadena+i)=='-'){
            bzero(aux, 100);
            strncpy(aux, cadena + i + 1, s);
            aux[strlen(aux)] = '-';
            strncpy(output + last, aux, strlen(aux));
            last += s + 1;
            s = 0;
            continue;
        }
        s++;
    }
    bzero(aux, 100);
    strncpy(aux, cadena, s);
    strncpy(output + last, aux, strlen(aux));
}
int main(int argc, char const *argv[])
{
    Respuesta servidor(7200);
    char salida[4000];
    struct mensaje m = servidor.getRequest();
    cout << m.arguments << endl;
    inverse(m.arguments,salida);
    cout <<salida << endl;
    servidor.sendReply(salida,m.IP,m.puerto);
}

