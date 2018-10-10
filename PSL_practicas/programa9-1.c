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

int main(void)
{
   int num[2];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   while(1) {
      recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      
      res = num[0] + num[1];
    printf("Puerto: %d\n",  ntohs(msg_to_client_addr.sin_port));
    printf("Direccion IP = ");
    printf("Res = %d",res);
    printIp(msg_to_client_addr.sin_addr.s_addr);
    sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}

