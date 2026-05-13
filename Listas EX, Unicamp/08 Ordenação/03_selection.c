#include <stdio.h>

void troca(int* a, int* b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

void print_vetor(int* v, int n){
	for(int i=0; i<n; i++){
		printf("%d ",v[i]);
	}printf("\n");
}


//Bom para trocas custosas
void selection(int* v, int n){
	int trocas_possiveis = 1;

	for(int i=0; i<n-1 && trocas_possiveis; i++){//elementos a esquerda do i jah estao ordenados, teremos os menores elementos do vetor
		trocas_possiveis = n-(i+1);

		int min = n-1;
		for(int j = n-2; j>=i; j--){//o j precisa ir até o i, pq o i pode ser o min
			if(v[j]<=v[min]){
				min = j;
				trocas_possiveis--; printf("trocas_possiveis: %d\n", trocas_possiveis);
				//obs q sempre q o min trocar de posicao, ou seja sempre q encontrar um elemento menor q min, ocorre um decremento
				//e se chegar a zero o min passou por todas as posicoes do vetor. Importante q essa decrementacao deve ser feita tbm se
				//houver elementos iguais. Assim o vetor já está ordenado.
			}
		}
		if(i != min) troca(&v[i],&v[min]);
		print_vetor(v,n);
	}
}

int main(){
	int vetor[10] = {10,1,1,1,1,1,1,1,1,1};
	selection(vetor, 10);

	return 0;
}