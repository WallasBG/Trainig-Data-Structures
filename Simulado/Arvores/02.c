#include<stdio.h>
#include<stdlib.h>

typedef struct no *p_no;

struct no {
	int chave;
	p_no esq, dir;
};

p_no inserir(p_no raiz, int chave) {
	p_no novo;
	if (raiz == NULL) {
		novo = malloc(sizeof(struct no));
		novo->esq = novo->dir = NULL;
		novo->chave = chave;
		return novo;
	}
	if (chave < raiz->chave)
		raiz->esq = inserir(raiz->esq, chave);
	else
		raiz->dir = inserir(raiz->dir, chave);
	return raiz;
}

//*
p_no buscar(p_no raiz, int chave) {
	if(!raiz || raiz->chave == chave) return raiz;

	if(chave > raiz->chave) return buscar(raiz->dir, chave);
	if(chave < raiz->chave) return buscar(raiz->esq, chave);
}

//*
p_no minimo(p_no raiz) {
	if(!raiz || !raiz->esq) return raiz;
	return minimo(raiz->esq);
}

//*
// void remover_sucessor(p_no raiz) {
// 	...
// }

//*
p_no remover_rec(p_no raiz, int chave) {
	if(!raiz) return NULL;

	if(raiz->chave == chave){
		
		if(raiz->esq && raiz->dir){//tem 2 filhos
			p_no min = minimo(raiz->dir);
			raiz->chave = min->chave;
			raiz->dir = remover_rec(raiz->dir, min->chave);
		}

		else if(raiz->dir){//tem filho dir
			p_no aux = raiz->dir;
			free(raiz);
			return aux;
		}

		else{//tem filho esq ou nao tem filho
			p_no aux = raiz->esq;
			free(raiz);
			return aux;
		}	
	}

	else if(chave > raiz->chave) raiz->dir = remover_rec(raiz->dir, chave);
	else if(chave < raiz->chave) raiz->esq = remover_rec(raiz->esq, chave);
	return raiz;
	
}

int numero_nos(p_no raiz) {
	if (raiz == NULL)
		return 0;
	return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int altura(p_no raiz) {
	if (raiz == NULL)
		return 0;
	int h_esq = altura(raiz->esq);
	int h_dir = altura(raiz->dir);
	return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

void imprime(p_no raiz) {
	if (raiz != NULL) {
		imprime(raiz->esq);
		printf("%d ", raiz->chave); /* visita raiz */
		imprime(raiz->dir);
	}
}

int folhas(p_no raiz) {
	if (raiz == NULL)
		return 0;
	if (raiz->esq == NULL && raiz->dir == NULL)
		return 1;
	return folhas(raiz->esq) + folhas(raiz->dir);
}

int main()
{
	p_no arvore = NULL;
	int num, busca;

	// Insere elementos na ABB
	scanf("%d", &num);
	while (num > 0) {
		arvore = inserir(arvore, num);
		scanf("%d", &num);
	}
	// Remove elementos da ABB
	scanf("%d", &num);
	while (num > 0) {
		arvore = remover_rec(arvore, num);
		scanf("%d", &num);
	}
	
	printf("Elementos inordem: ");
	imprime(arvore);
	printf("\n");
	printf("Numero de nos: %d\n", numero_nos(arvore));
	printf("Numero de folhas: %d\n", folhas(arvore));
	printf("Altura da arvore: %d\n", altura(arvore));
	printf("Menor elemento: %d\n", minimo(arvore)->chave);
	
	// Busca elemento
	scanf("%d", &busca);
	printf("Encontrou o elemento %d? ", busca);
	if (buscar(arvore, busca) != NULL)
		printf("Sim!\n");
	else
		printf("Não!\n");

	return 0;
}