#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** aloca_matriz(int linhas, int colunas){
	int** M = (int**) malloc(linhas * sizeof(int*));
	if(!M) return NULL;

	for(int i=0; i<linhas; i++){
		M[i] = (int*) malloc(colunas * sizeof(int));
		if(!M[i]){
			free(M);
			return NULL;
		}
	}

	return M;
}

void preenche_matriz(int*** M, int linhas, int colunas){
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			scanf("%d", &(*M)[i][j]);
		}
	}
}

void print_matriz(int*** M, int linhas, int colunas){
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++) printf("% 1d ", (*M)[i][j]);
		printf("\n");
	}
}

void permuta_linhas(int*** M, int n, int i, int j){
	if(i>=n || j>=n) return;

	int* aux = (*M)[i];
	(*M)[i] = (*M)[j];
	(*M)[j] = aux;
}

int det(int**M, int linhas, int colunas){
	int trocas=0;
	if(colunas != linhas){
		printf("erro, matriz nao eh quadrada\n");
		return -1;//poderia ser um valor real de det, mas nao eh
	}

	for(int i=0; i<colunas-1; i++){
		for(int j=i+1; j<linhas; j++){
			if(!M[i][i] && i+1<linhas){
				trocas++;
				permuta_linhas(&M,linhas,i,i+1);
			}int v[colunas];
			for(int k=i; k<colunas; k++){
				v[k] = -1*M[i][k]*M[j][i]; //printf("%d\n",v[k]);
				v[k] /= M[i][i]; //printf("%d\n",v[k]);
				v[k] += M[j][k]; //printf("%d\n",v[k]);
			}
			for(int w=i; w<colunas; w++){
				M[j][w] = v[w];

			}
		}
	}
	int dete = (int) pow(-1,trocas);
	for(int i=0; i<linhas; i++){
		dete *= M[i][i];
	}
	return dete;
}

int det3x3(int**M){
	int det = M[0][0]*(M[1][1]*M[2][2] -M[1][2]*M[2][1]);
	det -= M[0][1]*(M[1][0]*M[2][2] -M[1][2]*M[2][0]);
	det += M[0][2]*(M[1][0]*M[2][1] -M[1][1]*M[2][0]);

	return det;
}

int main(){
	int** M = aloca_matriz(3,3);
	preenche_matriz(&M, 3, 3); int det3X3 = det3x3(M);
	int dete = det(M, 3,3);
	printf("%d\n", dete);
	printf("%d\n", det3X3);

	return 0;
}