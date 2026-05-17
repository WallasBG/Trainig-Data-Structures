#include <stdio.h>

void print_vetor(int* v, int n){
	for(int i=0; i<n; i++)printf("%d ", v[i]);
	printf("\n");
}

void trocar(int* a, int* b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

int particao(int* v, int esq, int dir){
	int pos = dir+1, pivo = v[esq];
	for(int i=dir; i>=esq; i--){
		if(v[i]>=pivo){
			pos--; trocar(&v[i],&v[pos]);
		}
	}
	return pos;
}

void quick_sort_S(int* v, int esq, int dir){
	if(esq<dir){
		int pos_pivo = particao(v, esq, dir);
		print_vetor(v,6);
		quick_sort_S(v, esq, pos_pivo-1);
		quick_sort_S(v, pos_pivo+1, dir);
	}

}




int main(){
	int v[] = {6,1,5,3,2,4};
	quick_sort_S(v,0,5);


	return 0;
}