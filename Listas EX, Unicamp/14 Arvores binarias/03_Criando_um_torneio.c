#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

typedef struct no{
	int dado;
	no *esq, *dir;	
}no;

no *cria_no(int valor){
	no *novo_no = malloc(sizeof(no));
	novo_no->dado = valor;
	novo_no->esq = NULL;
	novo_no->dir = NULL;
	return novo_no;
}



no *cria_arvore(int valor, no *esq, no *dir){
	no *novo_no = cria_no(valor);
	novo_no->esq = esq;
	novo_no->dir = dir;
	return novo_no;
}

no *torneio(int *vetor, int ini, int fim){
	if(ini == fim) return cria_arvore(vetor[ini], NULL, NULL);
	int meio = (ini+fim)/2;
	no *esq = torneio(vetor, ini, meio);
	no *dir = torneio(vetor, meio+1, fim);

	return esq->dado > dir->dado ? cria_arvore(esq->dado, esq, dir) : cria_arvore(dir->dado, esq, dir);
}

typedef struct fila{
    no **v;
    int ini, fim, capacidade;
}fila;

fila *cria_fila(int capacidade){
    fila *f = malloc(sizeof(fila));
    f->capacidade = capacidade;

    f->v = malloc(f->capacidade * sizeof(no*));
    f->ini = f->fim = 0;
    return f;
}

void enfileirar(no *raiz, fila *f){
    f->v[f->fim++] = raiz;
}

no *desenfileira(fila *f){
    return f->v[f->ini++];
}

void percorrendo_largura(no *raiz){
    fila *f = cria_fila(100);
    no *r = raiz;
    
    enfileirar(r,f);
    while(f->ini < f->fim){
		r = desenfileira(f);

        if(r->esq) enfileirar(r->esq,f);
        if(r->dir) enfileirar(r->dir,f);
        
		printf("%d ", r->dado);
    }
	printf("\n");
}

int main(){
	//7,4,3,2,6,8
	int v[] = {5,1,7,4,3,2,6,8};
	no *arvore = torneio(v,0,7);
	// printf("%d\n", arvore->dado);

	// printf("%d\n", arvore->esq->dado);
	// printf("%d\n", arvore->dir->dado);

	// printf("%d\n", arvore->esq->esq->dado);
	// printf("%d\n", arvore->esq->dir->dado);
	percorrendo_largura(arvore);

	
  return 0;
}
