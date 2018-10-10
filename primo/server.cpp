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

int isprime(unsigned int n,unsigned int li,unsigned int ls){
    
    for(register unsigned int i = li; i <= ls; i++){
        if (n%i == 0){
            return 1;
        }
    }
    return 0; 
}

int main(int argc, char const *argv[])
{
    SocketDatagrama s1(atoi(argv[1]));
    int num[3];
    char dd[] = "0.0.0.0";
    cout << "Iniciando Servidor" << endl;
    PaqueteDatagrama p1((char*)num,3*sizeof(int),dd,0);
    s1.recibe(p1);
    memcpy((char*)num,p1.obtieneDatos(),p1.obtieneLongitud());
    int dato = isprime(num[0],num[1],num[2]);
    PaqueteDatagrama p2((char*)&dato,sizeof(int),p1.obtieneDireccion(),p1.obtienePuerto());
    s1.envia(p2);
    return 0;
}
