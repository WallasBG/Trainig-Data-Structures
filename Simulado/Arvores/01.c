#include<stdio.h>
#include<stdlib.h>

typedef struct no *p_no;

struct no {
	int dado;
	p_no esq, dir;
};

p_no inserir(p_no raiz, int x) {
	p_no novo;
	if (raiz == NULL) {
		novo = malloc(sizeof(struct no));
		novo->esq = novo->dir = NULL;
		novo->dado = x;
		return novo;
	}
	if (x < raiz->dado)
		raiz->esq = inserir(raiz->esq, x);
	else
		raiz->dir = inserir(raiz->dir, x);
	return raiz;
}

//*
int numero_nos(p_no raiz) {
	if(!raiz) return 0;
	return 1 + numero_nos(raiz->esq) + numero_nos(raiz->dir);
}

//*
int altura(p_no raiz) {
	if(!raiz) return 0;

	int altura_esq = altura(raiz->esq);
	int altura_dir = altura(raiz->dir);
	return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

//*
void inordem(p_no raiz) {
	if(raiz){
		inordem(raiz->esq);
		printf("%d ", raiz->dado);
		inordem(raiz->dir);
	}
}

//*
int folhas(p_no raiz) {
	if(!raiz) return 0;
	if(!raiz->esq && !raiz->dir) return 1;
	return 0 + folhas(raiz->esq) + folhas(raiz->dir);
}

int main()
{
	p_no arvore = NULL;
	int num;

	scanf("%d", &num);
	while (num > 0) {
		arvore = inserir(arvore, num);
		scanf("%d", &num);
	}
	printf("Elementos inordem: ");
	inordem(arvore);
	printf("\n");
	printf("Numero de nos: %d\n", numero_nos(arvore));
	printf("Numero de folhas: %d\n", folhas(arvore));
	printf("Altura da arvore: %d\n", altura(arvore));

	return 0;
}
