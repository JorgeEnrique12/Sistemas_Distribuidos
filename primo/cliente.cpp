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

//2400000000

unsigned int calcRange(unsigned int n){
    return n/3;
}

int main(int argc, char const *argv[])
{
    SocketDatagrama s1(0);
    unsigned int number = atoi(argv[1]);
    char direccion1[INET_ADDRSTRLEN] = "10.100.74.28";
    char direccion2[INET_ADDRSTRLEN] = "10.100.74.137";
    char direccion3[INET_ADDRSTRLEN] = "10.100.68.115";
    char direccion0[INET_ADDRSTRLEN] = "0.0.0.0";
    unsigned int num[3];
    int resto=0;
    num[0] = number;
    num[1] = number - number*.3369;
    num[2] = number - 1;
    resto+=num[1];
    PaqueteDatagrama p1((char *)num,3*sizeof(int),direccion1,7200);
    s1.envia(p1);
    num[0] = number;
    num[1] = number - number*.39 -  number*.3369;
    num[2] = number - number*.3369 - 1;
    PaqueteDatagrama p2((char *)num,3*sizeof(int),direccion2,7201);
    s1.envia(p2);
    num[0] = number;
    num[1] = 2;
    num[2] = number - number*.39 -  number*.3369 - 1;
    PaqueteDatagrama p3((char *)num,3*sizeof(int),direccion3,7202);
    s1.envia(p3);

    for(register int i = 0; i < 3; i++){
        PaqueteDatagrama p4((char *)num,sizeof(int),direccion0,0);
        s1.recibe(p4);
        cout << p4.obtieneDireccion() << endl;
        memcpy(&num[i],p4.obtieneDatos(),p4.obtieneLongitud());
    }
    
    for(int i = 0; i < 3; i++){ 
        if (num[i]!= 0) {
            cout << "No es primo" << endl;
            return 0;
        }
    }
    cout << "Es primo" << endl;
    return 0;
}
