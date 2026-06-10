#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *prox;
}no;

typedef struct fila{
	no *fim;
}fila;

no *cria_no(int valor){
	no *novo = malloc(sizeof(no));
	if(!novo) return NULL;

	novo->valor = valor;
	novo->prox = NULL;

	return novo;
}

fila *cria_fila(){
	fila *f = malloc(sizeof(fila));
	if(!f) return NULL;

	no *dummy = malloc(sizeof(no));
	dummy->prox = dummy;
	f->fim = dummy;

	return f;
}

void enfileira(fila *f, int valor){
	no *novo = cria_no(valor);
	novo->prox = f->fim->prox;
	f->fim->prox = novo;
	f->fim = novo;
}

int desenfileira(fila *f){
	no *salva = f->fim->prox->prox;
	f->fim->prox->prox = salva->prox;

	if(salva == f->fim) f->fim = f->fim->prox;

	int dado = salva->valor;
	free(salva);
	return dado;
}

void detruir_lista(no *lista){
	no *dummy = lista;
	lista = lista->prox;
	while(dummy != lista){
		no *proximo = lista->prox;
		free(lista);
		lista = proximo;
	}

	free(dummy);
}

void destruir_fila(fila *f){
	f->fim = f->fim->prox;

	detruir_lista(f->fim);
	free(f);
}

void imprimir_fila(fila *f){
	no *dummy = f->fim->prox;
	no *atual = dummy->prox;

	while(dummy != atual){
		printf("%d ", atual->valor);
		atual = atual->prox;
	}
	printf("\n");
}

int main(){
	fila *minha_fila = cria_fila();
	enfileira(minha_fila,90);
	enfileira(minha_fila,78);
	enfileira(minha_fila,11);
	enfileira(minha_fila,94);
	imprimir_fila(minha_fila);

	printf("%d\n", desenfileira(minha_fila));
	imprimir_fila(minha_fila);
	printf("%d\n", desenfileira(minha_fila));
	imprimir_fila(minha_fila);
	printf("%d\n", desenfileira(minha_fila));
	imprimir_fila(minha_fila);
	printf("%d\n", desenfileira(minha_fila));
	imprimir_fila(minha_fila);

	enfileira(minha_fila, 111);
	imprimir_fila(minha_fila);

	destruir_fila(minha_fila);

	return 0;
}