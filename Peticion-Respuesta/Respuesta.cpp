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
#include "Respuesta.h"

using namespace std;

Respuesta::Respuesta(int puerto):socketlocal(puerto){}
struct mensaje Respuesta::getRequest(){

    struct mensaje res;
    char direccion[INET_ADDRSTRLEN] = "0.0.0.0";
    memcpy(&res.IP,direccion,INET_ADDRSTRLEN);
    res.puerto = 0;
    PaqueteDatagrama p2((char*)&res,4096,res.IP,res.puerto);
    socketlocal.recibe(p2);
    memcpy(&res,p2.obtieneDatos(),p2.obtieneLongitud());
    int puerto = p2.obtienePuerto();
    memcpy(&res.puerto,&puerto,sizeof(int));
    memcpy(&res.IP,p2.obtieneDireccion(),INET_ADDRSTRLEN);
    return res;

}
void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
    struct mensaje m;
    memcpy(&m.IP,ipCliente,INET_ADDRSTRLEN);
    memcpy(&m.arguments,respuesta,4000);
    m.messageType = 0;m.requestId = 0; m.puerto=puertoCliente; m.operationId = 1;
    PaqueteDatagrama p1((char *) &m,4096,m.IP,m.puerto);
    socketlocal.envia(p1);
    
}
