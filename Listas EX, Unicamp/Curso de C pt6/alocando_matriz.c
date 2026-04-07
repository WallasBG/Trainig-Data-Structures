#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int linha, int colunas){
	int **M = (int **)malloc(linha * sizeof(int*));
	if(!M) return NULL;

	for(int i=0; i<linha; i++){
		M[i] = (int *)malloc(colunas * sizeof(int));
		if(!M[i]) return NULL;
	}

	return M;
}

void zera(int ***M, int l, int c){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			(*M)[i][j] = 0;
		}
	}
}

int main(){
	int **Matriz = aloca_matriz(3,2);
	zera(&Matriz,3,2);
	Matriz[1][1] = 11;

	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			printf("%d ", Matriz[i][j]);
		}printf("\n");
	}


	return 0;
}