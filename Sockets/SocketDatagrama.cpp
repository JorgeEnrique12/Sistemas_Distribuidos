#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

using namespace std;



SocketDatagrama::SocketDatagrama(int puerto){
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));

}
SocketDatagrama::~SocketDatagrama(){}
int SocketDatagrama::recibe(PaqueteDatagrama &p){
    char data [p.obtieneLongitud()];
    char direccion[INET_ADDRSTRLEN];
    socklen_t clilen = sizeof(direccionForanea);
    cout << "Esperando leer..." << endl;
    int check = recvfrom(s, data, p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
    inet_ntop(AF_INET,&(direccionForanea.sin_addr),direccion,INET_ADDRSTRLEN);
    p.inicializaDatos(data);
    p.inicializaIp(direccion);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    return check;
}
int SocketDatagrama::envia(PaqueteDatagrama &p){
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    return sendto(s, p.obtieneDatos() ,p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}





