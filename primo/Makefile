server: server.cpp SocketDatagrama.o 
	g++ server.cpp SocketDatagrama.o PaqueteDatagrama.o -o main
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h 
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h 
	g++ PaqueteDatagrama.cpp -c

