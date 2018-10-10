
#include <iostream>  
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include<string.h>

 using namespace std; 

class Archivo
{
private:
   string nombre_archivo;
   int fd;
   char *contenido;
   size_t num_bytes;
public:
Archivo(string filename);
Archivo(string filename, int banderas, mode_t modo); 
size_t lee(size_t nbytes);
size_t escribe(void *buffer, size_t nbytes);
size_t obtiene_num_bytes();
const char *get_contenido();
~Archivo();
};

Archivo::Archivo(string filename) {
    num_bytes = 0;
    nombre_archivo = filename;
    contenido = NULL;
    fd = open(nombre_archivo.c_str(), O_RDONLY);
}

Archivo::Archivo(string filename, int banderas, mode_t modo) {
    num_bytes = 0;
    nombre_archivo = filename;
    contenido = NULL;
    fd = open(nombre_archivo.c_str(), banderas, modo);
}

size_t Archivo::lee(size_t nbytes) {
  
    contenido = (char*) realloc(contenido, num_bytes+nbytes);
    size_t n = read(fd, contenido+num_bytes, nbytes);
    num_bytes += n;
    return n;
}

size_t Archivo::escribe(void *buffer, size_t nbytes) {
    size_t bytes = write(fd, buffer, nbytes);
    return bytes;
}

size_t Archivo::obtiene_num_bytes() {
    return num_bytes;
}

const char* Archivo::get_contenido() {
    return contenido;
}

Archivo::~Archivo() {
    delete contenido;
    close(fd);
}

int main(int argc, char const *argv[]) {

    if(argc != 3) {
        printf("Forma de uso: %s archivo_origen archivo_destino\n", argv[0]);
        return -1;
    }

    Archivo original(argv[1]);
    Archivo destino(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666);

    size_t nbytes = 0;
    while((nbytes = original.lee(BUFSIZ)) > 0);

    destino.escribe((void *)original.get_contenido(), original.obtiene_num_bytes());

    return 0;
}
