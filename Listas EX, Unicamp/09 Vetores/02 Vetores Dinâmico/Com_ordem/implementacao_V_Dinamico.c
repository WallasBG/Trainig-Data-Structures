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

void adicionar_elemento(p_vetor v, int valor){//com ordem
    if(v->capacidade == v->n){//sem espaco
        int *temp = v->dados;
        v->capacidade *= 2;
        v->dados = malloc(v->capacidade * sizeof(int));

        int t=0, d=0, add_valor=0;

        while(t < v->n && !add_valor){
            if(temp[t] >= valor){
                v->dados[d++] = valor;
                add_valor=1;
            }
            else v->dados[d++] = temp[t++];
        }

        while(t < v->n) v->dados[d++] = temp[t++];
        if(!add_valor) v->dados[d++] = valor;

        free(temp);
    }
    else{//com espaco
        int i;
        for(i=v->n-1; i >= 0 && v->dados[i] > valor; i--){
            v->dados[i+1] = v->dados[i];        
        }
        v->dados[i+1] = valor;

    }
    v->n++;
}//O custo no final das contas ainda é O(n)

void remover_elemento_na_posicao(p_vetor v, int posicao){//com ordem, tbm no final eh O(n)
    if(v->n <= (1.0/4.0)*v->capacidade){//vazio o suficiente para criar outro menor.
        int *temp = v->dados;
        v->capacidade /= 2;
        v->dados = malloc(v->capacidade * sizeof(int));


        
        int i=0, t=0;
        while(t<v->n){
            if(t != posicao) v->dados[i++] = temp[t++];
            else t++;
        }
        free(temp);
    }

    else{//caso nao precise reduzir o vetor
        for(posicao; posicao<=v->n-2; posicao++){
            v->dados[posicao] = v->dados[posicao+1];
        }
    }
    v->n--;

}/*na hora de remover para evitar ficar com o vetor mt vazio, ao chegar em 1/4 cheio, dividimos
o vetor pela metade. E utilizando o 1/4 cheio, pq msm apos reduzir o vetor ainda teremos espaco
para novas adicoes sem precisar alocar um novo vetor imediatamente. Algo q ocorreria se usarmos
1/2 cheio.*/

int busca_bin(int *v, int esq, int dir, int valor){
    while(esq<=dir){
        int meio = (esq+dir)/2;
        if(v[meio] == valor) return meio;
        else if(valor > v[meio]) esq = meio+1;
        else if(valor < v[meio]) dir = meio-1;
    }
    return -1;
}

int buscar(p_vetor v, int valor){//busca bin
    return busca_bin(v->dados, 0, v->n -1, valor);
}

void imprimir(p_vetor v){
    for(int i=0; i<v->n; i++){
        printf("%d ",v->dados[i]);
    }printf("\n");
}