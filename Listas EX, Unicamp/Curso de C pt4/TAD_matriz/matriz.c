#include "matriz.h"

matriz matriz_nova(float[][MAX],int linha, int coluna);
void imprime_matriz(matriz m);
matriz matriz_adiciona(matriz a, matriz b);

matriz matriz_multiplica(matriz a, matriz b){
    if(a.colunas != b.linhas) return;

    matriz m; 
    m.colunas = b.colunas; m.linhas = a.linhas; 

    for(int n=0; n<a.linhas; n++){
        for(int k=0; k<m.colunas; k++){
            m.elementos[n][k] = 0;
            for(int j=0; j<b.linhas; j++)
                m.elementos[n][k] += a.elementos[n][j] * b.elementos[j][n];
        }
    }

    return m;
}

matriz matriz_multiplica_escalar(float l, matriz m);