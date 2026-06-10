#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
	int *dados;
	int capacidade;
	int topo;
}pilha;

pilha *cria_pilha(int capacidade){
	pilha *stack = malloc(sizeof(pilha));
	if(!stack) return NULL;

	stack->capacidade = capacidade;
	stack->dados = malloc(stack->capacidade * sizeof(int));
	stack->topo = 0;
	return stack;
}

void empliha(pilha *stack, int valor){
	stack->dados[stack->topo++] = valor;
}

int desempliha(pilha *stack){
	stack->topo--;
	return stack->dados[stack->topo];
}

void imprimi_pilha(pilha *p){
	for(int i=0; i<p->topo; i++){
		printf("%d ", p->dados[i]);
	}printf("\n");
}

int main(){
	pilha *p = cria_pilha(10);
	empliha(p,1);
	empliha(p,10);
	empliha(p,9);
	empliha(p,2);
	imprimi_pilha(p);

	printf("%d\n",desempliha(p));
	imprimi_pilha(p);

	return 0;
}