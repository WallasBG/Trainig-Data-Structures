#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

typedef struct no{
	int dado;
	no *esq, *dir;	
}no;

typedef struct fila{
	no *ini, *fim;	
}fila;

no *cria_no(int valor){
	no *novo_no = malloc(sizeof(no));
	novo_no->dado = valor;
	novo_no->esq = NULL;
	novo_no->dir = NULL;
	return novo_no;
}

fila *cria_fila(){
	fila *f = malloc(fila);
	l->ini = NULL;
	l->fim = NULL;
	return l;
}

void emfileira(fila *f, int valor){
	no *novo_no = cria_no(valor);

	if(!fila->fim){
		f->ini = novo_no;
	}


	else{
		novo_no->dir = f->fim->dir;
		f->fim->dir = novo_no;
	} 
	
	f->fim = novo_no;


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

void profundidade_lateral(no *raiz){
	fila *f = cria_fila();
	while(raiz){
		emfileira(f,);
	}
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

	
  return 0;
}
