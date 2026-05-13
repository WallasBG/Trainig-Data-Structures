#include <stdio.h>

int buscabin(int *Vetor, int Esquerda, int Direita, int procurado){
	if(Esquerda > Direita) return -1;

	int chute = (Esquerda + Direita) / 2;

	if(Vetor[chute] == procurado) return chute;

	if(Vetor[chute]>procurado) Direita = chute-1;//return buscabin(Vetor, Esquerda, Chute-1, procurado);
	else if(Vetor[chute]<procurado) Esquerda = chute+1;//return buscabin(Vetor, Chute+1, Direita, procurado);

	return buscabin(Vetor, Esquerda, Direita, procurado);
}

int main(){
	int V[5] = {2,5,6,7,8};
	printf("%d\n", buscabin(V, 0, 5, 7));
	printf("%d\n", buscabin(V, 0, 5, 0));
	printf("%d\n", buscabin(V, 0, 5, 8));

	return 0;
}