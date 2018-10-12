
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
#include "PaqueteDatagrama.h"
using namespace std;

        char *datos;
        char ip[16];
        unsigned int longitud; 
        int puerto;

PaqueteDatagrama::PaqueteDatagrama(char * m, unsigned int l, char * ipp, int p){
    longitud = l;
    puerto = p;
    datos = (char *)malloc(longitud);
    memset(ip,0,sizeof(ip));
    memcpy(datos,m,longitud);
    memcpy(ip,ipp,strlen(ipp));

}
PaqueteDatagrama::~PaqueteDatagrama(){}
char * PaqueteDatagrama::obtieneDireccion(){
    return ip;
}
unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}
int PaqueteDatagrama::obtienePuerto(){
    return puerto;
}
char * PaqueteDatagrama::obtieneDatos(){
    return datos;
}
void PaqueteDatagrama::inicializaPuerto(int p){
    puerto = p;
}
void PaqueteDatagrama::inicializaIp(char * ipp){
    memcpy(ip,ipp,strlen(ipp));
}
void PaqueteDatagrama::inicializaDatos(char * m){
    memcpy(datos,m,longitud);
} 