#include "Vetor.h"
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

void adicionar_elemento(p_vetor v, int valor){//com ordem O(n), manter ordenado
	int i;
	for(i=v->n-1; i>=0 && v->dados[i] > valor; i--){
		v->dados[i+1] = v->dados[i];
	}
	v->dados[i+1] = valor;
	v->n++;
}

void remover_elemento_na_posicao(p_vetor v, int posicao){//Com ordem O(n), manter ordenado
	for(posicao; posicao < v->n-1; posicao++){
		v->dados[posicao] = v->dados[posicao+1];
	}
	v->n--;
}

int busca_binaria(int* v, int valor, int esq, int dir){
	if(esq > dir) return -1;

	int meio = (esq + dir) /2;
	if(v[meio] == valor) return meio;
	if(v[meio] < valor) return busca_binaria(v, valor, meio+1, dir);//direita
	return busca_binaria(v, valor, esq, meio-1);//esquerda	
}

int buscar(p_vetor v, int valor){//Com ordem O(log(n)), busca binaria
	return busca_binaria(v->dados, valor, 0, v->n-1);
}

void imprimir(p_vetor v){
	for(int i=0; i<v->n; i++)printf("%d ", v->dados[i]);
	printf("\n");
}