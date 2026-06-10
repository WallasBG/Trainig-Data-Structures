#include <stdio.h>
#include <stdlib.h>

typedef struct str_vetor{
	int *dados;
	int quant_elementos;
	int capacidade;
	int ini, fim;
}str_vetor;

str_vetor *cria_vetor(int capacidade){
	str_vetor *vetor = malloc(sizeof(str_vetor));
	if(!vetor) return NULL;

	vetor->capacidade = capacidade;
	vetor->quant_elementos = 0;
	vetor->ini = 0; vetor->fim = 0;

	vetor->dados = malloc(vetor->capacidade * sizeof(int));
	return vetor;
}

void enfileira(str_vetor *v, int valor){
	v->dados[v->fim] = valor;
	v->fim = (v->fim +1) % v->capacidade;
	v->quant_elementos++;
}

int desenfileira(str_vetor *v){
	int dado = v->dados[v->ini];
	v->ini = (v->ini +1) % v->capacidade;
	v->quant_elementos--;

	return dado;
}

void imprimi(str_vetor *v){
	int I = v->ini;

	if(v->fim == v->ini && v->quant_elementos > 0){
		printf("%d ", v->dados[I]);
		I = (v->ini + 1) % v->capacidade;
	}

	for(int i=I; i != v->fim; i=(i+1) % v->capacidade){
		printf("%d ",v->dados[i]);
	}
	printf("\n");
}

int main(){
	str_vetor *v = cria_vetor(8);

	for(int i=1; i<=10; i++){
		if(v->quant_elementos >= v->capacidade) break;
		enfileira(v, i*9);
		imprimi(v);
	}
	enfileira(v, 78);//perdi um valor, aq a fila eh limitada. Tenha em mente a capacidade fixa
	//Pode usar vetor dinamico ou lista ligada.
	imprimi(v);

	printf("%d\n",desenfileira(v));
	imprimi(v);
	printf("%d\n",desenfileira(v));
	imprimi(v);
	printf("%d\n",desenfileira(v));
	imprimi(v);

	enfileira(v, 111);
	imprimi(v);

	for(int i=0; i<v->capacidade; i++){//vetor na realidade
		printf("%d ", v->dados[i]);
	}printf("\n");

	printf("%d\n",desenfileira(v));
	imprimi(v);
	printf("%d\n",desenfileira(v));
	imprimi(v);
	printf("%d\n",desenfileira(v));
	imprimi(v);
	printf("%d\n",desenfileira(v));
	imprimi(v);
	printf("%d\n",desenfileira(v));
	imprimi(v);
	printf("%d\n",desenfileira(v));
	imprimi(v);
	printf("%d\n",desenfileira(v));
	imprimi(v);

	free(v->dados);
	free(v);

	return 0;
}