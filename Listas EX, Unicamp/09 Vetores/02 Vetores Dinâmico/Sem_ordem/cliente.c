#include "V_Dinamico.h"
#include <stdio.h>

int main(){
    p_vetor vetor_D = criar_vetor_vazio(1);
    for(int i=0; i<6; i++){
        int input; scanf("%d",&input);
        adicionar_elemento(vetor_D,input);
        imprimir(vetor_D);
        printf("capacidade: %d\n", vetor_D->capacidade);
    }

    printf("\nRemovendo...\n\n");

    for(int i=0; i<5; i++){
        remover_elemento_na_posicao(vetor_D,1);
        imprimir(vetor_D);
        printf("capacidade: %d\n", vetor_D->capacidade);
        printf("vazios: %d\n\n", vetor_D->capacidade - vetor_D->n);
    }

    return 0;
}