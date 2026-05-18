#include "Vetor.h"
#include <stdio.h>

int main(){
	p_vetor v = criar_vetor_vazio(10);
	adicionar_elemento(v, 1);
	adicionar_elemento(v, 3);
	adicionar_elemento(v, 0);
	adicionar_elemento(v, -11);//adicao O(n), mantem ordem

	imprimir(v);
	printf("%d\n",buscar(v,0)); //busca binaria, O(log(n))
	remover_elemento_na_posicao(v,1);//remocao O(n)
	imprimir(v);
	printf("%d\n",buscar(v,3));
	destruir_vetor(v);
}