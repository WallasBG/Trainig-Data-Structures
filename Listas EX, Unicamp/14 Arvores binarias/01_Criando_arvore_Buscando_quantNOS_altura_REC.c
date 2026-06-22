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

no *buscar(no *raiz, int procurado){
	if(!raiz || raiz->dado == procurado)
		return raiz;
	no *esq = buscar(raiz->esq, procurado);//olhar a subarvore a esquerda da raiz
	if(esq) return esq;//se encontrou o no, na sub arvore da esquerda
	return buscar(raiz->dir, procurado);//caso nao encontrou nada na sub arvore da esquerda, procuro na
	//sub arvore da direita

/*pq desse if(esq)? Bem esse if eh usado para retornar um no valido (!= NULL), onde esse retorno do no valido so ocorre se o procurado for
encontrado, caso contrario (retorno == NULL) nao achei o no procuro, e devo procurar na esquerda. Se fosse um retorno sem if ele iria procurar
so na esquerda, se tiver la ok, mas se nao tivesse?*/	
}

int quant_no(no* raiz){
	if(!raiz) return 0;
	return 1 + quant_no(raiz->esq) + quant_no(raiz->dir);
}//Estou em um no, se ele nao for nulo deve ser contado assim como os nos da sub arvore a sua esquerda e a direita

int altura_arvore(no* raiz){
	if(!raiz) return 0;

	int altura_esquerda = altura_arvore(raiz->esq);
	int altura_direita = altura_arvore(raiz->dir);
	return 1 + (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);
}//Estou em um no, se ele nao for nulo, a altura ate entao eh ele e a maior altura das sub arvores a esquerda e a direita

int main(){
	no *raiz = cria__arvore(1, NULL, NULL);
	no *raiz2 = cria__arvore(2, NULL, NULL);
	raiz = cria__arvore(3,raiz,raiz2);
	
	raiz2 = cria__arvore(6,NULL,NULL);
	raiz2 = cria__arvore(5,raiz2,NULL);
	raiz2 = cria__arvore(4, NULL, raiz2);

	raiz = cria__arvore(100,raiz,raiz2);
	raiz2 = NULL;

	// printf("raiz: %d\n", raiz->dado);
	// no *atual = raiz;
	// while(1){
	// 	int i; scanf("%d", &i);
		
	// 	if(i==-1){
	// 		atual = atual->esq;
	// 	}
	// 	else if(i == 1){
	// 		atual = atual->dir;
	// 	}
	// 	else if(i == 0) break;
	// 	printf("%d\n",atual->dado);
	// }

	no *achei =  buscar(raiz, 6);
	printf("%d\n", achei->dado);

	printf("quant no: %d\n", quant_no(raiz));
	printf("altura: %d\n", altura_arvore(raiz));

	return 0;
}
