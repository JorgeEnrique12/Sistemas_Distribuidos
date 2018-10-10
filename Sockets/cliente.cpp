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
    SocketDatagrama s1(6666);
    char mensaje[] = "HOla";
    int num[2];
    num[0] = 6;
    num[1] = 6;
    char direccion[INET_ADDRSTRLEN];
    strcpy(direccion, argv[1]);
    PaqueteDatagrama p1((char *)num,2*sizeof(int),direccion,7200);
    cout << "Enviando..." << endl;
    memcpy(num,p1.obtieneDatos(),p1.obtieneLongitud());
    cout << "Datos: "<<num[0] <<endl;
    cout << "Datos: "<<num[1] <<endl;
    s1.envia(p1);
    int res[1];
    char direccion2[] = "0.0.0.0";
    PaqueteDatagrama p2((char*)res,sizeof(int),direccion2,0);
    s1.recibe(p2);
    memcpy((char*)res,p2.obtieneDatos(),p2.obtieneLongitud());
    cout << "Res: "<< res[0] << endl;
    return 0;
}
