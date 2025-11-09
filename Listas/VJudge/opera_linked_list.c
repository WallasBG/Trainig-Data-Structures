#include <stdio.h>
#include <stdlib.h>

/*
fN insere o numero N no comeco da lista ex f7;

iMN insere o numero N na posicao M da lista, contando do 
zero. se M for maior que o tamanho da lista, número vai 
para o final. (n se preocupe com indices negativos)
ex i58 coloca o 8 na posicao 5

r remove o primeiro elemento da lista. se lista vazia, nao
faz nada

dM remove o elemento na posicao M(comeca no zero). se M 
for maior que o tamanho da lista, nada acontece. (n se 
preocupe com indices negativos)

q encerra o programa.

usar scanf("%c", &temp); para capturar o '\n' e limpar
buffer de entrada.

saida
para linha, ou seja, para cada acao imprima a lista, se 
estiver vazia imprima "empty"


*/ 

typedef struct no{
	struct no *prox;
	struct no  *ant;
	int valor;
}no;

typedef struct{
	no *primeiro;
	no *end;
	int tamanho;
}lista;

no *cria_no(int valor){
	no *novo_no = (no *)malloc(sizeof(no));
	if(!novo_no) return NULL;

	novo_no->prox = NULL; novo_no->ant = NULL;
	novo_no->valor = valor;

	return novo_no; 
}

lista *cria_lista(){
	lista *pt_lista = (lista *)malloc(sizeof(lista));
	if(!pt_lista) return NULL;

	pt_lista->primeiro = NULL;
	pt_lista->end = NULL;
	pt_lista->tamanho = 0;

	return pt_lista;
}

void add(lista *pt_lista, int valor){
	no *novo_no = cria_no(valor);

	if(!pt_lista->primeiro){//lista vazia
		pt_lista->end = novo_no;
	}
	else{
		novo_no->prox = pt_lista->primeiro;
		pt_lista->primeiro->ant = novo_no;
	}
	pt_lista->primeiro = novo_no;

	pt_lista->tamanho++;	
}

void remover(lista *pt_lista){
	no *atual = pt_lista->primeiro;
	if(atual){//lista nao vazia
		no *proximo = atual->prox;

		if(!proximo){//so um elemento
			pt_lista->end = NULL;
		}
		else{
			proximo->ant = atual->ant;
		}
		pt_lista->primeiro = atual->prox;
		free(atual);
		pt_lista->tamanho--;
	}
}

void append(lista *pt_lista,int valor){

	if(!pt_lista->primeiro){//lista vazia
		add(pt_lista, valor);
	}
	else{
		no *novo_no = cria_no(valor);
		novo_no->ant = pt_lista->end;
		pt_lista->end->prox = novo_no;
		pt_lista->end = novo_no;
		pt_lista->tamanho++;
	}

}

void insert(lista *pt_lista, int posi, int valor){
	//se maior no final
	//inserir no comeco
	//inserir no final
	//insrir no meio
	if(posi >= pt_lista->tamanho){
		append(pt_lista, valor);
	}
	else if(!posi){//inserir na 0
		add(pt_lista, valor);
	}
	else{//no meio
		no *novo_no = cria_no(valor);
		int idx=0; no *atual = pt_lista->primeiro;

		while(atual && idx != posi){
			atual = atual->prox;
			idx++;
		}
		no *anterior = atual->ant;

		novo_no->ant = anterior; novo_no->prox = atual;
		anterior->prox = novo_no; 
		atual->ant = novo_no;
		pt_lista->tamanho++;
	}
}

void delete(lista *pt_lista, int posi){
	
	if(posi < pt_lista->tamanho){
		no *anterior = NULL, *atual = NULL, *proximo = NULL;

		if(!posi){//primeiro
			remover(pt_lista);
		} 
		else if(posi == pt_lista->tamanho - 1){//ultimo
			atual = pt_lista->end;
			anterior = atual->ant;
			anterior->prox = atual->prox;
			free(atual);
			pt_lista->tamanho--;
		}
		else{//remocao no meio
			atual = pt_lista->primeiro; int idx=0;
			while(atual && idx != posi){
				atual = atual->prox;
				idx++;
			}
			anterior = atual->ant; proximo = atual->prox;
			anterior->prox = atual->prox;
			proximo->ant = atual->ant;
			free(atual);
			pt_lista->tamanho--;
		}
	}
}

void print_list(lista *pt_lista){
	no *atual = pt_lista->primeiro;

	if(!pt_lista->tamanho)printf("empty\n");
	else{
		while(atual){
			printf("%d ", atual->valor);
			atual = atual->prox;
		}
		printf("\n");
	}	
}


void main_func(lista *pt_lista){
	char in, temp;

	while(1){
		scanf("%c", &in);
		if(in == 'f'){
			int N; scanf("%d",&N); scanf("%c", &temp);
			add(pt_lista, N);
		}
		else if(in == 'i'){
			int M,N; scanf("%d%d",&M, &N); scanf("%c", &temp);
			insert(pt_lista, M, N);
		}
		else if(in == 'r'){
			scanf("%c", &temp);
			remover(pt_lista);
		}
		else if(in == 'd'){
			int M; scanf("%d", &M); scanf("%c", &temp);
			delete(pt_lista, M);
		}
		else if(in == 'q') break;
		print_list(pt_lista);
	}
}

void free_all(lista *pt_lista){
	no *atual = pt_lista->primeiro;
	while(atual){
		no *proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	free(pt_lista);
}

 

int main(){
	lista *my_list = cria_lista();
	main_func(my_list);
	free_all(my_list);
	return 0;
}