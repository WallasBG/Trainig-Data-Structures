#include <stdio.h>
#include <stdlib.h>

/*
 TAD - Lista legada
*/

typedef struct no *p_no;

struct no {
	int dado;
	p_no prox;
};

void destruir_lista(p_no lista) {
	if (lista != NULL) {
		destruir_lista(lista->prox);
		free(lista);
	}
}

void imprime_lista(p_no lista) {
	p_no atual;
	for (atual = lista; atual != NULL; atual = atual->prox)
		printf("%d ", atual->dado);
	printf("\n");
}

/*
 TAD - Pilha com lista ligada
*/

typedef struct pilha *p_pilha;

struct pilha {
	p_no topo;
};

p_pilha criar_pilha () {
	p_pilha p;
	p = malloc(sizeof(struct pilha));
	p->topo = NULL;
	return p;
}

void destruir_pilha(p_pilha p) {
	destruir_lista(p->topo);
	free(p);
}

void imprime_pilha(p_pilha p) {
	imprime_lista(p->topo);
}

typedef struct no no;

no *cria_no(int valor){
	no *novo = malloc(sizeof(no));
	novo->dado = valor;
	novo->prox = NULL;
	return novo;
}

void empilha(p_pilha pilha , int valor) {
	no *novo = cria_no(valor);
	novo->prox = pilha->topo;
	pilha->topo = novo;
}

int desempilha(p_pilha pilha) {
	no *salva = pilha->topo;
	int dado = salva->dado;
	pilha->topo = pilha->topo->prox;
	free(salva);
	return dado;
}

int main()
{
	p_pilha pilha;
	int num;

	pilha = criar_pilha();
	
	// Empilha
	scanf("%d", &num);
	while(num != 0) {
		empilha(pilha, num);
		scanf("%d", &num);
	}
	imprime_pilha(pilha);

	// Desempilha
	scanf("%d", &num);
	for (; num > 0; num--)
		desempilha(pilha);
	imprime_pilha(pilha);

	destruir_pilha(pilha);
	
	return 0;
}