#include <stdio.h>
#include <stdlib.h>

float **aloca_matriz(int linha, int colunas){
	float **M = (float **)malloc(linha * sizeof(float*));
	if(!M) return NULL;

	for(int i=0; i<linha; i++){
		M[i] = (float *)malloc(colunas * sizeof(float));
		if(!M[i]) return NULL;
	}

	return M;
}

void preenche_matriz_ID(float*** M, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j==i){
				(*M)[i][j] = 1;
				continue;
			} 
			(*M)[i][j] = 0;
		}
	}
}

void preenche_matriz(float*** M, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) scanf("%f", &(*M)[i][j]);
	}
}

void permuta_linhas(float*** M, int n, int i, int j){
	if(i>=n || j>=n) return;

	float* aux = (*M)[i];
	(*M)[i] = (*M)[j];
	(*M)[j] = aux;
}

float** multiplica_matrizes(float*** A, float*** B, int n){
	float** nova = aloca_matriz(n,n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			nova[i][j] = 0;
			for(int k=0; k<n; k++) nova[i][j] += (*A)[i][k] * (*B)[k][j];
		}
	}
	return nova;
}

float** pertumacaoXmatriz(float*** P, float*** M, int n){
	float** nova = aloca_matriz(n,n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if((*P)[i][j]) nova[i] = (*M)[j];
		}
	}
	return nova;
}

void print_matriz(float*** M, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("% 3.2f ", (*M)[i][j]);
		}printf("\n");
	}
}

int main(){
	printf("--------01------\n\n");

	int n, j, i;
	scanf("%d", &n); scanf("%d", &i); scanf("%d", &j);
	printf("\n");

	float** Matriz = aloca_matriz(n,n);
	preenche_matriz(&Matriz, n);
	permuta_linhas(&Matriz, n, i, j);
	print_matriz(&Matriz, n);printf("\n");

	printf("--------02------\n\n");

	float** ID = aloca_matriz(n,n);
	preenche_matriz_ID(&ID, n);
	print_matriz(&ID, n);printf("\n");

	permuta_linhas(&ID, n, i, j);
	print_matriz(&ID, n);printf("\n");

	float** nova = multiplica_matrizes(&ID, &Matriz, n);
	print_matriz(&nova, n);printf("\n");

	printf("--------03------\n\n");

	int m; scanf("%d", &m);
	float** A = aloca_matriz(m,m);
	preenche_matriz(&A, m);printf("\n");
	print_matriz(&A,m);printf("\n");

	float** P = aloca_matriz(m,m); preenche_matriz_ID(&P, m);
	permuta_linhas(&P, m, 0,2); permuta_linhas(&P, m, 1,3);
	print_matriz(&P, m);printf("\n");

	float** PxA_semContas = pertumacaoXmatriz(&P, &A, m);
	print_matriz(&PxA_semContas, m);

	return 0;
}

//agora tem q fazer uma funcao que le a matriz pertumacao e identifique quias linhas tem q trocar, sem fazer as contas de soma e produto.
//sera uma operacao mais rapida