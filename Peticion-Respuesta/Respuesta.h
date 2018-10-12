#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "SocketDatagrama.h"
#include "mensaje.h"

class Respuesta{
public:
   Respuesta(int puerto);
   struct mensaje getRequest(void);
   void sendReply(char *respuesta, char *ipCliente, int puertoCliente);
private:
    SocketDatagrama socketlocal;
};

 #endif