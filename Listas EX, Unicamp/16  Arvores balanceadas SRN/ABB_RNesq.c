#include <stdio.h>
#include <stdlib.h>

enum cor {PRETO,VERMELHO};
typedef enum cor color;
typedef struct no no;

struct no{
	int chave;
	no *esq, *dir;
	color cor;
};

int eh_vermelho(no *raiz){
	if(!raiz) return 0;
	if(raiz->cor == VERMELHO) return 1;
	return 0;
}

int eh_preto(no *raiz){
	if(!raiz) return 1;
	return raiz->cor == PRETO;
}

no *rotacao_esquerda(no *raiz){
	no *x = raiz->dir;
	raiz->dir = x->esq;
	x->esq = raiz;

	x->cor = raiz->cor;
	raiz->cor = VERMELHO;
	return x;
}

no *rotacao_direita(no *raiz){
	no *x = raiz->esq;
	raiz->esq = x->dir;
	x->dir = raiz;

	x->cor = raiz->cor;
	raiz->cor = VERMELHO;
	return x;
}

void sobe_vermelho(no *raiz){
	raiz->cor = VERMELHO;
	raiz->esq->cor = raiz->dir->cor = PRETO;
}

no *inseri_rec(no *raiz, int chave){
	if(!raiz){
		no *novo_no = malloc(sizeof(no));
		novo_no->esq = novo_no->dir = NULL;
		novo_no->chave = chave;
		novo_no->cor = VERMELHO;
		return novo_no;
	}
	else if(chave > raiz->chave) raiz->dir = inseri_rec(raiz->dir, chave);
	else raiz->esq = inseri_rec(raiz->esq, chave);

	if(eh_preto(raiz->esq) && eh_vermelho(raiz->dir)) raiz = rotacao_esquerda(raiz);
	if(eh_vermelho(raiz->esq) && eh_vermelho(raiz->esq->esq)) raiz = rotacao_direita(raiz);
	if(eh_vermelho(raiz->esq) && eh_vermelho(raiz->dir)) sobe_vermelho(raiz);

	return raiz;
}

no *inserir(no *raiz, int chave){
	raiz = inseri_rec(raiz, chave);
	raiz->cor = PRETO;
	return raiz;
}

typedef struct no_esp{
	no *arv;
	struct no_esp *prox;	
}no_esp;

typedef struct {
	no_esp *ini, *fim;	
}fila;

fila *cria_fila(){
	fila *f = malloc(sizeof(fila));
	f->ini = f->fim = NULL;
	return f;
}

void enfileira(fila *f, no *raiz){
	no_esp *novo_no = malloc(sizeof(no_esp));
	novo_no->arv = raiz;
	novo_no->prox = NULL;

	if(!f->fim) f->ini = novo_no;
	else f->fim->prox = novo_no;

	f->fim = novo_no;
}

no *desenfileira(fila *f){
	no_esp *salva = f->ini;
	no *dado = salva->arv;

	f->ini = f->ini->prox;
	if(!f->ini)f->fim = NULL;

	free(salva);
	return dado;
}

void imprime_largura(no *raiz){
	fila *f = cria_fila();
	enfileira(f,raiz);

	while(f->ini){
		raiz = desenfileira(f);
		if(raiz->esq) enfileira(f, raiz->esq);
		if(raiz->dir) enfileira(f, raiz->dir);

		printf("(%d ", raiz->chave);
		if(raiz->cor == PRETO) printf("PRETO) ");
		else printf("VERMELHO) ");
	}
	printf("\n");
	free(f);
}

void free_arvore(no *raiz){
	if(raiz){
		free_arvore(raiz->esq);
		free_arvore(raiz->dir);
		free(raiz);
	}
}

int main(){
	no *raiz = NULL;
	raiz = inserir(raiz, 1);
	imprime_largura(raiz);

	raiz = inserir(raiz, 2);
	imprime_largura(raiz);

	raiz = inserir(raiz, 3);
	imprime_largura(raiz);

	raiz = inserir(raiz, 4);
	imprime_largura(raiz);

	raiz = inserir(raiz, 5);
	imprime_largura(raiz);

	raiz = inserir(raiz, 8);
	imprime_largura(raiz);

	raiz = inserir(raiz, 6);
	imprime_largura(raiz);

	free_arvore(raiz);

  return 0;
}
