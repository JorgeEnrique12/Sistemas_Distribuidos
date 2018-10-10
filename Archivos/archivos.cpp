#include <iostream>  
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include<string.h>

 using namespace std; 

class Archivo{
private:
   string nombreArchivo;
   int fd;
   char* contenido = NULL;
   size_t num_bytes;
public:
Archivo(string filename);
Archivo(string filename, int banderas, mode_t modo);
size_t lee(char *buffer);
size_t escribe(char *buffer, size_t nbytes);
size_t obtieneNum_bytes();
string getName();
char* get_contenido();
~Archivo();
};
string Archivo::getName(){
    return nombreArchivo;
} 
Archivo::Archivo(string f){
    nombreArchivo = f;
    contenido = NULL;
    fd = open(nombreArchivo.c_str(), O_RDONLY);
}
Archivo::Archivo(string filename, int banderas, mode_t modo){
    nombreArchivo = filename;
    contenido = NULL;
    fd = open(nombreArchivo.c_str(), modo, banderas);

}
Archivo::~Archivo(){
    close(fd);
}
size_t Archivo::lee(char *buffer){
    int n = read(fd, buffer, sizeof (buffer));
    char *ptr;
    ptr = (char *)realloc(contenido, num_bytes+n);
    contenido = ptr;
    memcpy ( contenido+num_bytes, buffer,strlen(buffer));
    num_bytes+=n;
    return n;

}
size_t Archivo::escribe(char *buffer, size_t nbytes){
    write(fd,buffer, nbytes);
    int x = obtieneNum_bytes();
    return nbytes;
}
size_t Archivo::obtieneNum_bytes(){
    return num_bytes;
}
char* Archivo::get_contenido(){
    return contenido;
}
int main(int argc, char const *argv[])
{
    if(argc != 3) {
        printf("Forma de uso: %s archivo_origen archivo_destino\n", argv[0]);
        exit(-1);
    }
    Archivo f1(argv[1]);
    Archivo f2 (argv[2],0777,O_WRONLY|O_TRUNC|O_CREAT);
    char *buffer = (char*)malloc(BUFSIZ*sizeof(char));
    size_t bytes;
    while((bytes = f1.lee(buffer)) > 0){
        ;
    }

}

