#include <stdio.h>

typedef struct no no;

typedef struct no{
	int dado;
	no *esq, *dir;
}no;

void pre_ordem(no *raiz){
	if(raiz){
		printf("%d\n", raiz->dado);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void pos_ordem(no *raiz){
	if(raiz){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%d\n", raiz->dado);
	}
}

void in_ordem(no *raiz){
	if(raiz){
		in_ordem(raiz->esq);
		printf("%d\n", raiz->dado);
		in_ordem(raiz->dir);
	}
}

int main(){

  return 0;
}
