#include "V_Dinamico.h"
#include <stdlib.h>
#include <stdio.h>

p_vetor criar_vetor_vazio(int capacidade){
    p_vetor novo = malloc(sizeof(struct vetor));

	novo->capacidade = capacidade;
	novo->n = 0;
	novo->dados = malloc(capacidade * sizeof(int));

	return novo;
}

void destruir_vetor(p_vetor v){
    free(v->dados);
    free(v);
}

void adicionar_elemento(p_vetor v, int valor){//sem ordem
    if(v->capacidade == v->n){//sem espaco
        int *temp = v->dados;
        v->capacidade *= 2;
        v->dados = malloc(v->capacidade * sizeof(int));

        for(int i=0; i < v->n; i++){
            v->dados[i] = temp[i];
        }
        free(temp);
    }
    v->dados[v->n] = valor;
    v->n++;
}//O custo no final das contas ainda é O(1)

void remover_elemento_na_posicao(p_vetor v, int posicao){//sem ordem
    if(v->n <= (1.0/4.0)*v->capacidade){
        int *temp = v->dados;
        v->capacidade /= 2;
        v->dados = malloc(v->capacidade * sizeof(int));

        for(int i=0; i<v->n; i++){
            v->dados[i] = temp[i];
        }
        free(temp);
    }
    v->dados[posicao] = v->dados[v->n-1];
    v->n--;
}/*na hora de remover para evitar ficar com o vetor mt vazio, ao chegar em 1/4 cheio, dividimos
o vetor pela metade. E utilizando o 1/4 cheio, pq msm apos reduzir o vetor ainda teremos espaco
para novas adicoes sem precisar alocar um novo vetor imediatamente. Algo q ocorreria se usarmos
1/2 cheio.*/

int buscar(p_vetor v, int valor){//busca sequencial
    for(int i=0; i<v->n; i++){
        if(v->dados[i] == valor) return i;
    }
    return -1;

}

void imprimir(p_vetor v){
    for(int i=0; i<v->n; i++){
        printf("%d ",v->dados[i]);
    }printf("\n");
}