#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz(int d, int n){
	int **coord = (int **)malloc(n * sizeof(int*));
	if(!coord) return NULL;

	for(int i=0; i<n; i++){
		(*coord)[i] = (int*)malloc(d * sizeof(int));
		if(!(*coord)[i]) return NULL;
	}

	return coord;
}

float* centroide(int** M, int d, int n){
	float* centro = (float *)malloc(d * sizeof(float));
	if(!centro) return NULL;

	for(int i=0; i<d; i++){
		centro[i] = 0.0;
		for(int j=0; j<n; j++) centro[i] += M[j][i]/n;
	}

	return centro;
}

//dist dois pontos
//dist ponto ao centroide

int main(){
    int d, n;
    scanf("%d", &d); scanf("%d", &n);

    int** matriz_pontos = aloca_matriz(d,n);
    float* centroide_pontos = centroide(matriz_pontos, d, n);




    return 0;
}