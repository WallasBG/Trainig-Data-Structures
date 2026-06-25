#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

typedef struct no{
	int dado;
	no *esq, *dir;	
}no;

no *cria__arvore(int dado, no *esq, no *dir){
	no *novo_no = malloc(sizeof(no));
	novo_no->dado = dado;
	novo_no->esq = esq; novo_no->dir = dir;
	return novo_no;
}

int comparador(no *r1, no* r2){
    if(!r1 && !r2) return 1;
    if(!r1 || !r2) return 0;
    return r1->dado==r2->dado && comparador(r1->esq, r2->esq) && comparador(r1->dir, r2->dir);
}

int main(){
    no *raiz = cria__arvore(1, NULL, NULL);
	no *raiz2 = cria__arvore(2, NULL, NULL);
	raiz = cria__arvore(3,raiz,raiz2);
	
	raiz2 = cria__arvore(6,NULL,NULL);
	raiz2 = cria__arvore(5,raiz2,NULL);
	raiz2 = cria__arvore(4, NULL, raiz2);

	raiz = cria__arvore(100,raiz,raiz2);
	raiz2 = NULL;

    no *raiz3 = cria__arvore(1, NULL, NULL);
	raiz2 = cria__arvore(2, NULL, NULL);
	raiz3 = cria__arvore(3,raiz3,raiz2);
	
	raiz2 = cria__arvore(6,NULL,NULL);
	raiz2 = cria__arvore(5,raiz2,NULL);
	raiz2 = cria__arvore(4, NULL, raiz2);

	raiz3 = cria__arvore(100,raiz3,raiz2);
	raiz2 = NULL;

    printf("igual? %d\n", comparador(raiz,raiz3));

    return 0;
}