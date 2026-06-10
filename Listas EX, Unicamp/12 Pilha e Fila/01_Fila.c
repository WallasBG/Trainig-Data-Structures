#include <stdio.h>
#include <stdlib.h>

typedef struct no * p_no;

typedef struct no{
	int valor;
	struct no *prox;
}no;

typedef struct fila{
	p_no ini;
	p_no fim;
}fila;

p_no cria_no(int valor){
	p_no novo = malloc(sizeof(no));
	if(!novo) return NULL;

	novo->valor = valor;
	novo->prox = NULL;
}

fila *cria_fila(){
	fila *f = malloc(sizeof(fila));
	if(!f) return NULL;

	f->ini = NULL;
	f->fim = NULL;
	return f; 
}

void destruir_lista(p_no lista){
	if(lista){
		destruir_lista(lista->prox);
		free(lista);
	}
}

void destruir_fila(fila *f){
	destruir_lista(f->ini);
	free(f);
}

void enfileira(fila *queue, int valor){//append na lista ligada
	p_no novo = cria_no(valor);

	//fila vazia
	if(!queue->ini) queue->ini = novo;
	//n vazia
	else queue->fim->prox = novo;
	queue->fim = novo;
}

int desenfileira(fila *queue){//remover e retorna 1 da lista ligada
	//cuidado ao remover em fila unitaria
	if(!(queue->ini->prox)) queue->fim = NULL;

	int dado = queue->ini->valor;
	p_no aux = queue->ini->prox; 
	free(queue->ini);
	queue->ini = aux;
	return dado;
}

void imprimi_lista(p_no lista){
	if(lista){
		printf("%d ", lista->valor);
		imprimi_lista(lista->prox);
	}else printf("\n");
}

void imprimi_fila(fila *pt_fila){
	imprimi_lista(pt_fila->ini);
}

int main() {
	fila *my_queue = cria_fila();

	enfileira(my_queue, 89);
	imprimi_fila(my_queue);
	printf("%d\n",desenfileira(my_queue));
	imprimi_fila(my_queue);

	enfileira(my_queue, 9);
	enfileira(my_queue, 89);
	enfileira(my_queue, 18);
	enfileira(my_queue, 94);
	enfileira(my_queue, 101);
	imprimi_fila(my_queue);

	printf("%d\n",desenfileira(my_queue));
	imprimi_fila(my_queue);
	printf("%d\n",desenfileira(my_queue));
	imprimi_fila(my_queue);

	return 1;
}
