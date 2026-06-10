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
 TAD - Fila com lista ligada
*/

typedef struct fila *p_fila;

struct fila {
	p_no ini , fim; // inicio e fim da fila
};

p_fila criar_fila () {
	p_fila f;
	f = malloc(sizeof(struct fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void destruir_fila(p_fila f) {
	destruir_lista(f->ini);
	free(f);
}

void imprime_fila(p_fila f) {
	imprime_lista(f->ini);
}

p_no cria_no(int valor){
	p_no novo = malloc(sizeof(struct no));
	novo->dado = valor;
	novo->prox = NULL;
	return novo;
}

void enfileira(p_fila f, int x) {
	p_no novo = cria_no(x);
	
	if(!f->ini) f->ini = novo;
	else{
		novo->prox = f->fim->prox;
		f->fim->prox = novo;
	}

	f->fim = novo;
}

int desenfileira(p_fila f) {
	p_no salva = f->ini;
	int dado = f->ini->dado;

	f->ini = f->ini->prox;
	if(!f->ini) f->fim = f->ini;
	free(salva);
	return dado;
}

int main()
{
	p_fila fila;
	int num;

	fila = criar_fila();
	
	// Efileira
	scanf("%d", &num);
	while(num != 0) {
		enfileira(fila, num);
		scanf("%d", &num);
	}
	imprime_fila(fila);

	// Desenfileira
	scanf("%d", &num);
	for (; num > 0; num--)
		desenfileira(fila);
	imprime_fila(fila);

	destruir_fila(fila);
	
	return 0;
}