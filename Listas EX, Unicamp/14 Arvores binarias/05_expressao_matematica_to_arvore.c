#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no no;

struct no{
	int dado;
	no *esq, *dir;
};

no *cria_arvore(int dado, no *esq, no *dir){
	no *novo_no = malloc(sizeof(no));
	novo_no->dado = dado;
	novo_no->esq = esq; novo_no->dir = dir;
	return novo_no;
}

no *expressao_to_arvore(char *expressao, int ini, int fim){
	if(ini == fim) return cria_arvore(expressao[ini], NULL, NULL);

	int pos, prece = 2;
	for(int i=ini; i<= fim; i++){
		if((expressao[i] == '+' || expressao[i] == '-') && 0 <= prece){
			prece = 0;
			pos = i;
		}
		else if((expressao[i] == '*' || expressao[i] == '/') && 1 <= prece){
			prece = 1;
			pos = i;
		}
	}

	no *esq = expressao_to_arvore(expressao, ini, pos-1);
	no *dir = expressao_to_arvore(expressao, pos+1, fim);
	return cria_arvore(expressao[pos], esq, dir);
}

void pre_ordem(no *raiz){
	if(raiz){
		printf("%c ", raiz->dado);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void pos_ordem(no *raiz){
	if(raiz){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%c ", raiz->dado);
	}
}

void in_ordem(no *raiz){
	if(raiz){
		in_ordem(raiz->esq);
		printf("%c ", raiz->dado);
		in_ordem(raiz->dir);
	}
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

		printf("%c ", r->dado);
    }
	printf("\n");
}



int main(){
	char exp[] = "1-2*3+4";
	no *raiz = expressao_to_arvore(exp, 0, strlen(exp)-1);
	in_ordem(raiz); printf("\n");
	pos_ordem(raiz); printf("\n");
	pre_ordem(raiz); printf("\n");
	percorrendo_largura(raiz);

	return 0;
}