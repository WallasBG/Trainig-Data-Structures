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

void adicionar_elemento(p_vetor v, int valor){//sem ordem O(1)
	if(v->capacidade > v->n){
		v->dados[v->n] = valor;
		v->n++;
	}
	else printf("Vetor cheio\n");
}

void remover_elemento_na_posicao(p_vetor v, int posicao){//sem ordem O(1)
	v->dados[posicao] = v->dados[v->n -1];
	v->n--;
}

int buscar(p_vetor v, int valor){//sem ordem O(n)
	for(int i=0; i<v->n; i++){
		if(v->dados[i] == valor) return i;
	}
	return -1;
}

void imprimir(p_vetor v){
	for(int i=0; i<v->n; i++)printf("%d ", v->dados[i]);
	printf("\n");
}