#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** aloca_matriz(int d, int n){
	int **coord = (int **)malloc(n * sizeof(int*));
	if(!coord) return NULL;

	for(int i=0; i<n; i++){
		coord[i] = (int*)malloc(d * sizeof(int));
		if(!coord[i]) return NULL;
	}

	return coord;
}

void preenche_matriz(int ***M, int n, int d){
	for(int i=0; i<n; i++)
		for(int j=0; j<d; j++) scanf("%d", &(*M)[i][j]);
}

float* centroide(int** M, int d, int n){
	float* centro = (float *)malloc(d * sizeof(float));
	if(!centro) return NULL;

	for(int i=0; i<d; i++){
		centro[i] = 0.0;
		for(int j=0; j<n; j++) centro[i] += (float) M[j][i]/n;
	}

	return centro;
}

float dist2pontos(int* A, float *B, int d){
	float dist = 0.0;

	for(int i=0; i<d; i++)
		dist += (A[i] - B[i]) * (A[i] - B[i]);
	dist = (float) sqrt(dist);

	return dist;
}

float* distTodospontosaocentroide(int** M, int n, float* centroide, int d){
	float* distTodos = (float*)malloc(n*sizeof(float));

	for(int i=0; i<n; i++) distTodos[i] = dist2pontos(M[i],centroide,d);

	return distTodos;
}

//dist dois pontos
//dist ponto ao centroide

int main(){
    int d, n;
    scanf("%d", &d); scanf("%d", &n);

    int** matriz_pontos = aloca_matriz(d,n);
    preenche_matriz(&matriz_pontos, n, d);
	float *centro = centroide(matriz_pontos, d, n);
    float* distAOcentroide =  distTodospontosaocentroide(matriz_pontos, n, centro, d);

	printf("Centroide: ");
	for(int i=0; i<d; i++) printf("%.2f ", centro[i]);
	printf("\n");

    for(int i=0; i<n; i++){
    	printf("Ponto: ");
    	for(int j=0; j<d; j++) printf("%d ", matriz_pontos[i][j]);
    	printf("Dist: %.2f\n", distAOcentroide[i]);
    }

    return 0;
}