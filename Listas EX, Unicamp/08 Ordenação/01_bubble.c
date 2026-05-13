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

void bubble(int* v, int n){
	int trocou = 1;

	for(int i=0; i<n-1 && trocou; i++){
		trocou = 0;
		for(int j=n-1; j>i; j--){
			if(v[j] < v[j-1]){
				troca(&v[j],&v[j-1]);
				trocou = 1;
			}
		}print_vetor(v,n);
	}
}

int main(){
	int vetor[5] = {5,3,1,6,9};
	//int vetor[5] = {5,3,6,-1,0};
	bubble(vetor, 5);

	return 0;
}