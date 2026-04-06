#include "matriz.h"
#include <stdio.h>

matriz matriz_nova(float elementos[][MAX],int linha, int coluna){
    matriz m;
    m.colunas = coluna; m.linhas = linha;

    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++) m.elementos[i][j] = elementos[i][j];
    
    return m;    
}
void imprime_matriz(matriz m){
    for(int i=0; i<m.linhas; i++){
        for(int j=0; j<m.colunas; j++){
            printf("% 3.2f ", m.elementos[i][j]);
        }printf("\n");
    }
}
matriz matriz_adiciona(matriz a, matriz b){
    matriz sum;
    sum.colunas = a.colunas; sum.linhas = a.linhas;

    for(int i=0; i<sum.linhas; i++){
        for(int j=0; j<sum.colunas; j++){
            sum.elementos[i][j] = a.elementos[i][j] + b.elementos[i][j];
        }
    }
    return sum;
}

matriz matriz_multiplica(matriz a, matriz b){
    //if(a.colunas != b.linhas) return; pensar em algo depois

    matriz m; 
    m.colunas = b.colunas; m.linhas = a.linhas; 

    for(int n=0; n<a.linhas; n++){
        for(int k=0; k<m.colunas; k++){
            m.elementos[n][k] = 0;
            for(int j=0; j<b.linhas; j++)
                m.elementos[n][k] += a.elementos[n][j] * b.elementos[j][k];
        }
    }

    return m;
}

matriz matriz_multiplica_escalar(float l, matriz m){
    matriz result;
    result.colunas = m.colunas; result.linhas = m.linhas;

    for(int i=0; i<m.linhas; i++)
        for(int j=0; j<m.colunas; j++) result.elementos[i][j] = l * m.elementos[i][j];
    
    return result;    
}