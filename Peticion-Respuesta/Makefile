server: server.cpp Respuesta.o 
	g++ server.cpp Respuesta.o SocketDatagrama.o PaqueteDatagrama.o -o main

Respuesta.o: Respuesta.cpp Respuesta.o SocketDatagrama.o Respuesta.h
	g++ Respuesta.cpp -c

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.o PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
