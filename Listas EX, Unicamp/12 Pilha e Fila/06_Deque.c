#include <stdio.h>
#include <stdlib.h>


typedef struct no{
	int valor;
	struct no *ant,*prox;
}no;

typedef struct fila{
	no *ini, *fim;
}fila;

no *cria_no(int valor){
	no *novo = malloc(sizeof(no));
	if(!novo) return NULL;

	novo->valor = valor;
	novo->ant = NULL;
	novo->prox = NULL;
	return novo;
}

fila *cria_fila(){
	fila *f = malloc(sizeof(fila));
	if(!f) return NULL;

	f->ini = NULL;
	f->fim = NULL;

	return f;
}

void enfileira_append(fila *f, int valor){
	no *novo = cria_no(valor);

	if(!f->ini) f->ini = novo;
	else f->fim->prox = novo;
	novo->ant = f->fim;
	f->fim = novo;
}

void enfileira_add(fila *f, int valor){
	no *novo = cria_no(valor);
	if(!f->ini) f->fim = novo;
	else f->ini->ant = novo;

	novo->prox = f->ini;
	f->ini = novo;
}

int desenfileira_no_ini(fila *f){
	no *salva = f->ini;
	if(!f->ini->prox)f->fim = f->fim->prox;
	else f->ini->prox->ant = f->ini->ant;
	f->ini = f->ini->prox;
	
	int dado = salva->valor;
	free(salva);
	return dado;
}

int desenfileira_no_fim(fila *f){
	no *salva = f->fim;
	int dado = salva->valor;

	f->fim = f->fim->ant;
	if(!f->fim) f->ini = salva->ant;
	else f->fim->prox = salva->prox;

	free(salva);
	return dado;
}

void imprime_frente(fila *f){
	no *atual = f->ini;
	while(atual){
		printf("%d ", atual->valor);
		atual = atual->prox;
	}
	printf("\n");
}

void imprime_tras(fila *f){
	no *atual = f->fim;
	while(atual){
		printf("%d ", atual->valor);
		atual = atual->ant;
	}
	printf("\n");
}

int main(){

	fila *minha_fila = cria_fila();
	enfileira_append(minha_fila,5);
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	enfileira_add(minha_fila,4);
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	enfileira_append(minha_fila,3);
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	enfileira_add(minha_fila,1);
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	enfileira_append(minha_fila,0);
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	printf("--------------------------\n");

	printf("%d\n",desenfileira_no_ini(minha_fila));
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	printf("%d\n",desenfileira_no_fim(minha_fila));
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	printf("%d\n",desenfileira_no_ini(minha_fila));
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	printf("%d\n",desenfileira_no_fim(minha_fila));
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	printf("%d\n",desenfileira_no_fim(minha_fila));
	imprime_frente(minha_fila);
	imprime_tras(minha_fila);printf("\n");

	return 0;
}

