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

using namespace std;

bool isprime(unsigned int number){
    for(register unsigned int i = 2; i < number; i++)
    {   
        if(number%i == 0){
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    unsigned int number = atoi(argv[1]);
    isprime(number)?  cout << "Es primo" << endl:cout << "No es primo" << endl;
}
