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

void insertion(int* v, int n){
	for(int i=1; i<n; i++){
		for(int j=i; j>0 && v[j]<v[j-1]; j--){
			troca(&v[j], &v[j-1]);
			print_vetor(v,n);
		}
	}
}

int main(){
	int vetor[5] = {5,3,6,-1,0};
	insertion(vetor, 5);

	return 0;
}