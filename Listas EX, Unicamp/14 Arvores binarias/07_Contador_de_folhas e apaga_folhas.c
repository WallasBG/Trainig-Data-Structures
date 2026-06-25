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

int contador_folhas(no *raiz){
    if(!raiz) return 0;
    if(!raiz->esq && !raiz->dir) return 1;

    return contador_folhas(raiz->esq) + contador_folhas(raiz->dir);
}

no *apaga_folha(no *raiz, int valor){//remove todas as folhas com o certo valor
	if(!raiz) return NULL;
	if(!raiz->esq && !raiz->dir & raiz->dado == valor){
		free(raiz);
		return NULL;
	}

	raiz->esq = apaga_folha(raiz->esq, valor);
	raiz->dir = apaga_folha(raiz->dir, valor);
	return raiz;
}

int main(){

    int v[] = {5,1,7,4,3,2,6,8};
	no *arvore = torneio(v,0,7);
    printf("numero de folhas: %d\n", contador_folhas(arvore));
    
    no *raiz = cria_arvore(1, NULL, NULL);
	no *raiz2 = cria_arvore(2, NULL, NULL);
	raiz = cria_arvore(3,raiz,raiz2);
	
	raiz2 = cria_arvore(2,NULL,NULL);
	raiz2 = cria_arvore(5,raiz2,NULL);
	raiz2 = cria_arvore(4, NULL, raiz2);

	raiz = cria_arvore(100,raiz,raiz2);
	raiz2 = NULL;
    printf("numero de folhas: %d\n", contador_folhas(raiz));

	raiz = apaga_folha(raiz, 2);//remove todas folhas com 2
	printf("numero de folhas: %d\n", contador_folhas(raiz));

    return 0;
}