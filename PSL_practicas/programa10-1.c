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

int puerto = 7200;

void printIp(unsigned d){
    unsigned direccion;
    memcpy(&direccion,&d,sizeof(d));

    char str[12];
    sprintf(str+1, "%x", direccion);
    str[0] = '0';

    
    for(int i = strlen(str)-1; i>0; i-=2)
    {
        char c[2] = {str[i-1],str[i]};
        unsigned x = strtol(c,NULL,16);
        printf("%u",x);
        printf(".");
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
   msg_to_server_addr.sin_port = htons(puerto);
   
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(6666);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
    printf("Puerto: %u\n",    ntohs(msg_to_server_addr.sin_port));
    printf("Direccion IP = ");
    printIp(msg_to_server_addr.sin_addr.s_addr);
    printf("2 + 5 = %d\n", res);   

    
    
   close(s);
}

