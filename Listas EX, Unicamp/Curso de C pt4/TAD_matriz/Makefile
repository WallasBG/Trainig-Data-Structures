all: cliente

matriz.o: matriz.c matriz.h
	gcc -c matriz.c

cliente.o: cliente.c matriz.h
	gcc -c cliente.c

cliente: cliente.o matriz.o
	gcc cliente.o matriz.o -o cliente