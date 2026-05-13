all: cliente
	
cliente: cliente_cpx.o complexos.o
	gcc cliente_cpx.o complexos.o -lm -o cliente

cliente_cpx.o: cliente_cpx.c complexos.h
	gcc -c cliente_cpx.c

complexos.o: complexos.c complexos.h
	gcc -c complexos.c