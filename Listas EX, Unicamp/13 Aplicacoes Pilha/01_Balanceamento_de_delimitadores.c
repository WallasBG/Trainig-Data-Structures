//balanceamento de delimitadores

#include <stdio.h>
#include <stdlib.h>

//pilha implementada com vetores
typedef struct pilha2{
	int *vetor;
	int capacidade, topo;
}pilha2;

pilha2 *cria_pilha2(int capacidade){
	pilha2 *p = malloc(sizeof(pilha2));
	p->capacidade = capacidade;
	p->vetor = malloc(p->capacidade * sizeof(int));
	p->topo = 0;
	return p;
}

void empilha2(pilha2 *p, int valor){
	p->vetor[p->topo++] = valor;
}

int desempilha2(pilha2 *p){
	p->topo--;
	return p->vetor[p->topo];
}

void destruir(pilha2 *p){
	free(p->vetor);
	free(p);
}

int balanceada(char *expressao){
	int ok=1;
	pilha2 *p = cria_pilha2(100);

	for(int i=0; ok && expressao[i] != '\0'; i++){
		if(expressao[i] == '(' || expressao[i] == '[') empilha2(p, expressao[i]);
		else if(expressao[i] == ')' || expressao[i] == ']'){
			if(p->topo != 0){
				int op = desempilha2(p);
				if((expressao[i] == ')' && op != '(') || 
				(expressao[i] == ']' && op != '[')) ok = 0;
			}
			else ok = 0;
		}
	}
	if(p->topo != 0) ok=0;
	destruir(p);
	return ok;
}

int main(){

	char expressao[] = "(1)) + 2(8+8)[cubarsi])";
	printf("%d\n", balanceada(expressao));

	return 0;
}
