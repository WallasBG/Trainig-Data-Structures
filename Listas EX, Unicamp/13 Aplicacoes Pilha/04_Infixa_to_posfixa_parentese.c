#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	char operador;
	int precedencia;
	struct no *prox;
}no;

typedef struct pilha{
	no *topo;
}pilha;

pilha *cria_pilha(){
	pilha *p = malloc(sizeof(pilha));
	p->topo = NULL;
	return p;
}

int precedencia(char op, int parenteses){
	int precedencia = (op == '+' || op == '-') ? 0 + (2*parenteses) : 1 + (2*parenteses);
	return precedencia;
}

no *cria_no(int op, int parenteses){
	no *novo = malloc(sizeof(no));
	novo->operador = op;
	novo->precedencia = precedencia(op, parenteses);
	novo->prox = NULL;
	return novo;
}

void empilha(pilha *p, int op, int parenteses){
	no *novo = cria_no(op, parenteses);
	novo->prox = p->topo;
	p->topo = novo;
}

int desempilha(pilha *p){
	no *salva = p->topo;
	int dado = salva->operador;

	p->topo = salva->prox;
	free(salva);
	return dado;
}

char *infixa_to_posfixa(char *expresao){
	char *saida = malloc((strlen(expresao) + 1) * sizeof(char));
	pilha *p = cria_pilha();
	int parenteses = 0, idx=0;

	for(int i=0; expresao[i] != '\0'; i++){
		if(expresao[i] == ' ') continue;

		if(expresao[i] == '(') parenteses++;
		else if(expresao[i] == ')') parenteses--;
		else if(expresao[i] >= 48 && expresao[i] <= 57){
			saida[idx++] = expresao[i];
			saida[idx++] = ' ';
		}
		else{
			while(p->topo && p->topo->precedencia >= precedencia(expresao[i], parenteses)){
				saida[idx++] = desempilha(p);
				saida[idx++] = ' ';
			}
			empilha(p, expresao[i], parenteses);
		}
	}

	while(p->topo){
		saida[idx++] = desempilha(p);
		saida[idx++] = ' ';
	}
	free(p);
	saida[idx] = '\0';
	return saida;
}



int main(){

	char *expresao = "3*((4+2)/(2*3)-4)";
	printf("%s\n",infixa_to_posfixa(expresao));

  return 0;
}
