#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *prox;	
}no;

typedef struct pilha{
	no *topo;
}pilha;

no *cria_no(int valor){
	no *novo = malloc(sizeof(no));
	if(!novo) return NULL;

	novo->valor = valor;
	novo->prox = NULL;
	return novo;
}

pilha *cria_pilha(){
	pilha *stack = malloc(sizeof(pilha));
	if(!stack) return NULL;

	stack->topo = NULL;
	return stack;
}

void empilha(pilha *stack, int valor){
	no *novo = cria_no(valor);

	novo->prox = stack->topo;
	stack->topo = novo;
}

int desempilha(pilha *stack){
	no *salva = stack->topo;
	int dado = salva->valor;

	stack->topo = stack->topo->prox;
	free(salva);
	return dado;
}

void imprimi_pilha(pilha *stack){
	no *atual = stack->topo;
	while(atual){
		printf("%d ", atual->valor);
		atual = atual->prox;
	}
	printf("\n");
}

void destruir_pilha(pilha *stack){
	no *atual = stack->topo, *proximo;

	while(atual){
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	free(stack);
}

int main(){
	pilha *minha_pilha = cria_pilha();
	empilha(minha_pilha,100);
	imprimi_pilha(minha_pilha);
	empilha(minha_pilha,99);
	imprimi_pilha(minha_pilha);
	empilha(minha_pilha,23);
	imprimi_pilha(minha_pilha);
	empilha(minha_pilha,89);
	imprimi_pilha(minha_pilha);

	printf("-------------\n");
	printf("%d\n",desempilha(minha_pilha));
	imprimi_pilha(minha_pilha);
	printf("%d\n",desempilha(minha_pilha));
	imprimi_pilha(minha_pilha);
	printf("%d\n",desempilha(minha_pilha));
	imprimi_pilha(minha_pilha);
	printf("%d\n",desempilha(minha_pilha));
	imprimi_pilha(minha_pilha);

	empilha(minha_pilha,94);
	imprimi_pilha(minha_pilha);

	destruir_pilha(minha_pilha);



	return 0;
}