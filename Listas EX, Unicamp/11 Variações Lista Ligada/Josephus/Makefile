all: saida

implementacao.o: implementacao.c lista_circular.h
	gcc -c implementacao.c

problema_Josephus.o: problema_Josephus.c lista_circular.h
	gcc -c problema_Josephus.c

saida: problema_Josephus.o implementacao.o
	gcc implementacao.o problema_Josephus.o -o saida
