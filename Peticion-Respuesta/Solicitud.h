#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "SocketDatagrama.h"
#include "mensaje.h"

class Solicitud{
public:
    Solicitud();
    char * doOperation(char *IP, int puerto, int operationId, char *arguments); 
private:
    SocketDatagrama socketlocal; 
};

 #endif