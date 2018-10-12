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
#include "Solicitud.h"

using namespace std;

Solicitud::Solicitud():socketlocal(0){}

char* Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
    struct mensaje m;
    struct mensaje res;
    char direccion[INET_ADDRSTRLEN] = "0.0.0.0";
    memcpy(&m.IP,IP,INET_ADDRSTRLEN);
    memcpy(&res.IP,direccion,INET_ADDRSTRLEN);
    memcpy(&m.arguments,arguments,4000);
    m.messageType = 1;m.requestId = 0; m.puerto=puerto; m.operationId = operationId;
    res.puerto = 0;
    PaqueteDatagrama p1((char*)&m,4096,m.IP,m.puerto);
    socketlocal.envia(p1);
    PaqueteDatagrama p2((char*)&res,4096,res.IP,res.puerto);
    socketlocal.recibe(p2);
    memcpy(&res,p2.obtieneDatos(),p2.obtieneLongitud());
    char respuesta[4000];
    memcpy(respuesta,&res.arguments,4000);
    return (char *)respuesta;
}


struct mensaje m;
    
