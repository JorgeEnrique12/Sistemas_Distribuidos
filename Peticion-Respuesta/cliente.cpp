#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "Solicitud.h"
using namespace std;
#define ordenaCadena 1

int main(int argc, char const *argv[]){
    char cadena[4000]  = "JorgeEnrique-Samantha-Pablin";
    Solicitud cliente;
    char direccionserver[INET_ADDRSTRLEN];
    int puerto = atoi(argv[2]);
    memcpy(direccionserver,argv[1],INET_ADDRSTRLEN);
    printf("La respuesta del servidor es <%s>\n",cliente.doOperation (direccionserver, puerto, ordenaCadena, cadena));
}
