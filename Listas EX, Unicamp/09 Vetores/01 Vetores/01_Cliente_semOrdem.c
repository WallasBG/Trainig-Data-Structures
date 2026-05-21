#include "Vetor.h"
#include <stdio.h>

int main(){
	p_vetor v = criar_vetor_vazio(10);
	adicionar_elemento(v, 1);
	adicionar_elemento(v, 3);
	adicionar_elemento(v, 0);
	adicionar_elemento(v, -11);//adicao O(1) linear

	imprimir(v);
	printf("%d\n",buscar(v,0)); //busca sequencial O(n)
	remover_elemento_na_posicao(v,1);//remocao O(1) linear
	imprimir(v);
	printf("%d\n",buscar(v,0));
	destruir_vetor(v);
}