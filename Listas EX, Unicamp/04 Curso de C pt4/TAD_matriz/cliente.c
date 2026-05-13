#include <stdio.h>
#include "matriz.h"

int main(){
    float elementos1[][MAX] = {{1,2}, {3,4}};
    float elementos2[][MAX] = {{5,6}, {7,8}};

    matriz m1 = matriz_nova(elementos1, 2, 2);
    matriz m2 = matriz_nova(elementos2, 2, 2);

    matriz m1xm2 = matriz_multiplica(m1,m2);
    matriz _2xm1 = matriz_multiplica_escalar(2.0, m1);
    matriz m1SUMm2 = matriz_adiciona(m1, m2);

    printf("m1:\n"); imprime_matriz(m1);
    printf("\nm2:\n"); imprime_matriz(m2);
    printf("\nm1xm2:\n"); imprime_matriz(m1xm2);
    printf("\n2xm1\n"); imprime_matriz(_2xm1);
    printf("\nm1+m2\n"); imprime_matriz(m1SUMm2);

    float elementoA[][MAX] = {{1,2,3}, {4,5,6}};
    float elementoB[][MAX] = {{1,2},{3,4},{5,6}};
    float elementoC[][MAX] = {{1,2,3,4},{5,6,7,8}};

    matriz A = matriz_nova(elementoA, 2,3);
    matriz B = matriz_nova(elementoB, 3,2);
    matriz C = matriz_nova(elementoC, 2,4);

    matriz AxB = matriz_multiplica(A,B);
    matriz BxC = matriz_multiplica(B,C);
    printf("\nAxB:\n"); imprime_matriz(AxB);
    printf("\nBxC:\n"); imprime_matriz(BxC);
    
    return 0;
}
