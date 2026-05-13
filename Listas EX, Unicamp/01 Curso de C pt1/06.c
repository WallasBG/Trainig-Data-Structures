#include <stdio.h>
#include <limits.h>

typedef struct{
    int maior;
    int menor;
    int diff;
}MAIORmenor;

MAIORmenor maiorMenor(int *v, int n){
    int maior = INT_MIN, menor = INT_MAX;
    for(int i=0; i<n; i++){

        if(v[i] > maior) maior = v[i];
        if(v[i] < menor) menor = v[i];        
    }

    int diff = maior - menor;

    MAIORmenor saida;
    saida.diff = diff; saida.maior = maior; saida.menor = menor;

    return saida;
}

int main(){

    int n; scanf("%d", &n);
    int v[n];

    printf("Digite seus %d numeros: ", n);

    for(int i=0; i<n; i++){
        int x; scanf("%d", &v[i]);
    }

    MAIORmenor result = maiorMenor(v,n);
    printf("Diferenca abs eh %d\n", result.diff);
    
    return 0;
}