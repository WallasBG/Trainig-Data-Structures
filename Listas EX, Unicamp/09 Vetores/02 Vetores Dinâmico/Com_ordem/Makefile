all: saida_Ordem
	
saida_Ordem: implementacao_V_Dinamico.o cliente.o
	gcc implementacao_V_Dinamico.o cliente.o -o saida_Ordem

cliente.o: cliente.c V_Dinamico.h
	gcc -c cliente.c

implementacao_V_Dinamico.o: implementacao_V_Dinamico.c V_Dinamico.h
	gcc -c implementacao_V_Dinamico.c
