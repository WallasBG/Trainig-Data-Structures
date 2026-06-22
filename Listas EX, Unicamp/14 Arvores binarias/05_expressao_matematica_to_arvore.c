#include <stdio.h>
#include <stdlib.h>

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



int main(){
	char exp[] = "3-1/2*3+2";
	no *raiz = expressao_to_arvore(exp, 0, 8);
	in_ordem(raiz); printf("\n");
	pos_ordem(raiz); printf("\n");
	pre_ordem(raiz); printf("\n");

	return 0;
}