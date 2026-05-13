#include <stdio.h>
#include <stdlib.h>

void merge(int* V, int esq, int dir){//vetor com 2 metade ordenadas
	int i=esq, j=(esq + dir)/2 + 1, k=0;
	int* vetor_novo = (int*) malloc((dir-esq+1)*sizeof(int));

	while(i<=(esq + dir)/2 && j<=dir){
		if(V[i]<=V[j]) vetor_novo[k++] = V[i++];
		else vetor_novo[k++] = V[j++];
	}
	//i ou j acabou
	while(j<=dir) vetor_novo[k++] = V[j++];//i acabou, ainda temos j
	while(i<=(esq + dir)/2) vetor_novo[k++] = V[i++];//j acabou, ainda temos i

	for(int i=esq, k=0; i<=dir; i++, k++) V[i] = vetor_novo[k];
	free(vetor_novo);	
}

void merge_sort(int* V, int esq, int dir, int n){//coloquei o n aq so para imprimir o vetor apos cada merge
	int meio = (esq + dir)/2;

	if(esq<dir){
		merge_sort(V, esq, meio,n);
		merge_sort(V, meio+1, dir,n);

		merge(V,esq, dir);
		for(int i=0; i<n; i++)printf("%d ", V[i]);
		printf("\n");
	}
	
}

int main(){

	int V[7] = {5,3,7,1,6,2,4};
	merge_sort(V, 0, 6, 7);

	// for(int i=0; i<6; i++)printf("%d ", V[i]);
	// printf("\n");

	return 0;
}