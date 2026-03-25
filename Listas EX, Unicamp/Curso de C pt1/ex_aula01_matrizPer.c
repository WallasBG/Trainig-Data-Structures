#include <stdio.h>
#define MAX 100

int eh_permutacao(int M[][MAX], int n){
    for(int i=0; i<n; i++){
        int sum_row = 0 , sum_col = 0;

        for(int j=0; j<n; j++){
            sum_row += M[i][j];
            sum_col += M[j][i];
        }
        if(sum_col != 1 || sum_row != 1){
            if(sum_col != 1) printf("Erro coluna %d\n", i);
            if(sum_row != 1) printf("Erro linha %d\n", i);
            return 0;
        }
    }
    return 1;
}

void multiplica_matriz(int M[][MAX], int W[][MAX], int R[][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            R[i][j] = 0;
            for(int k=0; k<n; k++) R[i][j] += M[i][k] * W[k][j];
        }
    }
}

void ler_matrix_quadrada(int M[][MAX], int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) scanf("%d", &M[i][j]);
}

void print_matriz(int M[][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) printf("%d ", M[i][j]);
        printf("\n");
    }

}

int main(){

    int P[MAX][MAX], n; scanf("%d", &n);
    ler_matrix_quadrada(P,n); printf("\n");
    print_matriz(P,n); printf("\n");

    if(eh_permutacao(P,n)) printf("Eh permutacao\n"); 
    else printf("N eh permutacao\n");

    int M[MAX][MAX], m; scanf("%d", &m);
    ler_matrix_quadrada(M, m); printf("\n");
    print_matriz(M,m); printf("\n");

    int C[MAX][MAX];
    multiplica_matriz(M,P,C,n); //MATRIZ X PERMUTACAO, PERMUTA AS COLUNAS
    print_matriz(C,n); printf("\n");

    int D[MAX][MAX];
    multiplica_matriz(P,M,D,n); //PERMUTACAO X MATRIZ, PERMUTA AS LINHA
    print_matriz(D,n);



    return 0;
}