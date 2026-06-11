#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct no{
	int valor;
	struct no *prox;
}no;

typedef struct pilha{
	no *topo;
}pilha;

no *cria_no(int valor){
	no *novo = malloc(sizeof(no));
	if(!novo) return NULL;

	novo->valor = valor;
	novo->prox = NULL;
	return novo;
}

pilha *cria_pilha(){
	pilha *p = malloc(sizeof(pilha));
	if(!p) return NULL;

	p->topo = NULL;
	return p;
}

void empilha(pilha *p, int valor){
	no *novo = cria_no(valor);
	novo->prox =  p->topo;
	p->topo = novo;
}

int desempilha(pilha *p){
	no *salva = p->topo;
	int dado = salva->valor;

	p->topo = salva->prox;
	free(salva);
	return dado;
}

void destruir_pilha(pilha *p){
	no *atual = p->topo;
	while(atual){
		no *proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	free(p);
}

void imprimi(pilha *p){
	no *atual = p->topo;
	while(atual){
		printf("%d ",atual->valor);
		atual = atual->prox;
	}printf("\n");
}

int calcula_posfixa(char *expressao){
	pilha *p = cria_pilha();
	int result;

	for(int i=0; expressao[i] != '\0'; i++){
		if(expressao[i] == '+' || expressao[i] == '-'
		|| expressao[i] == '*' || expressao[i] == '/'){
			int b = desempilha(p), a = desempilha(p);
			
			switch(expressao[i]){
				case '+':
				result = a + b;
				break;

				case '-':
				result = a - b;
				break;

				case '*':
				result = a * b;
				break;

				case '/':
				result = a / b;
				break;
			}
			empilha(p,result);
		}
		else if(expressao[i]>= 48 && expressao[i]<=57){
			empilha(p, expressao[i]-48);
		}
	}
	result = p->topo->valor;
	destruir_pilha(p);
	return result;
}

int main(){
	//char expressao[] = "2 2 1 + 4 * 1 + *";
	char expressao[MAX];
	scanf("%[^\n]",expressao);
	printf("%d\n", calcula_posfixa(expressao));

	return 0;
}