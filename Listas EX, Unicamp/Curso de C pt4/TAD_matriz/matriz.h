#ifndef MATRIZ_H
#define MATRIZ_H
#define MAX 100

typedef struct{
    float elementos[MAX][MAX];
    int linhas;
    int colunas;
}matriz;

matriz matriz_nova(float[][MAX],int linha, int coluna);//Cria uma nova matriz, com dados do teclado
void imprime_matriz(matriz m);//Imprime a matriz m
matriz matriz_adiciona(matriz a, matriz b);// retorna a matriz a+b
matriz matriz_multiplica(matriz a, matriz b);// retorna a matriz a*b
matriz matriz_multiplica_escalar(float l, matriz m);// retorna a matriz l*b, onde l eh um escalar

#endif