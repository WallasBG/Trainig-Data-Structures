#include<stdio.h>
#include<stdlib.h>

/*
 TAD - Lista legada
*/

typedef struct no *p_no;

struct no {
	int dado;
	p_no prox;
};

void destruir_lista(p_no lista) {
	if (lista != NULL) {
		destruir_lista(lista->prox);
		free(lista);
	}
}

void imprime_lista(p_no lista) {
	p_no atual;
	for (atual = lista; atual != NULL; atual = atual->prox)
		printf("%d ", atual->dado);
	printf("\n");
}

/*
 TAD - Pilha com lista ligada
*/

typedef struct pilha *p_pilha;

struct pilha {
	p_no topo;
};

p_pilha criar_pilha () {
	p_pilha p;
	p = malloc(sizeof(struct pilha));
	p->topo = NULL;
	return p;
}

void destruir_pilha(p_pilha p) {
	destruir_lista(p->topo);
	free(p);
}

void imprime_pilha(p_pilha p) {
	imprime_lista(p->topo);
}

void empilha(p_pilha pilha , int valor) {
	p_no novo = malloc(sizeof(struct no));
	novo->dado = valor;
	novo->prox = pilha->topo;
	pilha->topo = novo;
}

int desempilha(p_pilha pilha) {
	p_no topo = pilha->topo;
	int valor = topo->dado;
	pilha->topo = pilha ->topo ->prox;
	free(topo);
	return valor;
}

int pilha_vazia(p_pilha p) {
	if(p->topo == NULL)
		return 1;
	return 0;
}

/*
 Funções
*/

int balanceada(char *expressao) {
	p_pilha pilha = criar_pilha();

	for(int i=0; expressao[i] != '\0'; i++){
		if(expressao[i] == '(') empilha(pilha, 1);
		else if(expressao[i] == '[') empilha(pilha, 2);

		else if(expressao[i] == ')' && pilha->topo && pilha->topo->dado == 1)
			desempilha(pilha);
		else if(expressao[i] == ']' && pilha->topo && pilha->topo->dado == 2)
			desempilha(pilha);
		else return 0;
	}

	if(!pilha->topo) return 1;
	return 0;
}

int main()
{
	char expressao[100];

	scanf("%s", expressao);
	printf("%d\n", balanceada(expressao));
	return 0;
}