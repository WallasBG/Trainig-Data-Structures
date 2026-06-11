#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
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

char *infixa_to_posfixa(char *expressao){
	pilha *p = cria_pilha();
	char *saida = malloc((strlen(expressao)+2) * sizeof(char));
	int e = 0;

	for(int i=0; expressao[i] != '\0'; i++){
		if(expressao[i]>= 48 && expressao[i]<=57){
			saida[e++] = expressao[i];
			saida[e++] = ' ';
		}

		else if(expressao[i] != ' '){

			if(expressao[i] == '-') expressao[i] = 44;
			else if(expressao[i] == '*') expressao[i] = 46;

			if(!p->topo) empilha(p, expressao[i]);//pilha vazia
			else{//n vazia
				int result = expressao[i] - p->topo->valor;
				
				while(result < 0 || result==0 ||
					result==1 || result==-1){

					int op = desempilha(p);
					if(op == 44) op = '-';
					else if(op == 46) op = '*';

					saida[e++] = op;
					saida[e++] = ' ';
					if(p->topo) result = expressao[i] - p->topo->valor;
					else break;
				}
				empilha(p, expressao[i]);
			}
		}	
	}
	while(p->topo){
		int op = desempilha(p);
		if(op == 44) op = '-';
		else if(op == 46) op = '*';

		saida[e++] = op;
	}saida[e] = '\0';
	free(p);

	return saida;
}
//seria bom q funcionace para numeros de mais de um alg.

int main(){
	char expressao[] = "1 + 2 * 3 / 4 * 5 - 6";
	printf("%s\n",infixa_to_posfixa(expressao));
	return 0;
}