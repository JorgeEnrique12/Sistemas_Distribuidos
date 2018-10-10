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
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
using namespace std; 


int main(int argc, char const *argv[])
{
    SocketDatagrama s1(7200);
    int num[2];
    int res[1];
    num[0] = 6;
    num[1] = 6;
    char direccion[] = "0.0.0.0";
    PaqueteDatagrama p1((char*)num,sizeof(int)*2,direccion,0);
    cout << "Iniciando Servidor" << endl;
    s1.recibe(p1);
    memcpy((char*)num,p1.obtieneDatos(),p1.obtieneLongitud());
    cout <<  num[0] <<endl ;
    cout <<  num[1] <<endl ;
    res[0] = num[0] + num[1];
    cout << "Suma:  " << res[0] << endl;
    PaqueteDatagrama p2((char*)res,sizeof(int),p1.obtieneDireccion(),p1.obtienePuerto());
    s1.envia(p2);
    return 0;
}
