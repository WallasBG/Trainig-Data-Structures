#include <stdio.h>

int max_rec(int *V, int n){
	if(n==1) return V[0];

	int m = max_rec(V, n-1);
	// a ideia é retornar o maior elemento entre a posicao n-1 e os elementos a sua esquerda
	// e se a posicao for 1, nao temos elementos a sua esquerda, o elemento da posicao 1, eh retornado

	//com o primeiro elemento em maos, pode se comparar com o elemento a esquerda dele.
	//fazendo a comparacao, retorna o maior, com esse maior faz a comparacao com o a esquerda dele.
	//e assim por diante

	if(V[n-1] > m) return V[n-1];
	else return m;
}

int main(){
	int v[4]={5,10,9,101};
	printf("%d\n", max_rec(v,4));

	return 0;
}