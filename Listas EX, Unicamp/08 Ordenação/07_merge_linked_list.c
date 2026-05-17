#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	struct no* prox;
	int valor;
}no;

typedef struct{
	no* pri;
	no* ultimo;
	int tamanho;
}lista;


lista* cria_lista(){
	lista* pt_lista = (lista*) malloc(sizeof(lista));
	if(!pt_lista) return NULL;

	pt_lista->pri = NULL; pt_lista->ultimo = NULL;
	pt_lista->tamanho = 0;
	return pt_lista;
}

no* cria_no(int valor){
	no* novo_no = (no*) malloc(sizeof(no));
	if(!novo_no) return NULL;

	novo_no->valor = valor;
	novo_no->prox = NULL;
	return novo_no;
}

void add(int valor, lista* pt_lista){
	no* novo_no = cria_no(valor);

	novo_no->prox = pt_lista->pri;
	if(!pt_lista->pri) pt_lista->ultimo = novo_no;
	pt_lista->pri = novo_no;
	pt_lista->tamanho++;
}

void append(int valor, lista* pt_lista){
	no* novo_no = cria_no(valor);

	if(!pt_lista->pri){//sem elementos
		novo_no->prox = pt_lista->pri;
		pt_lista->pri = novo_no;
	}
	else{//com elementos
		novo_no->prox = pt_lista->ultimo->prox;
		pt_lista->ultimo->prox = novo_no;
	}
	pt_lista->ultimo = novo_no;
	pt_lista->tamanho++;
}

void print_lista(lista* pt_lista){
	no* atual = pt_lista->pri;

	while(atual){
		printf("%d ", atual->valor);
		atual = atual->prox;
	}printf("\n");
}

void free_lista(lista* pt_lista){
	no* atual = pt_lista->pri;

	while(atual){
		no* proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	free(pt_lista);
}


void merge(no* esq, no* meio, no* dir){
	lista* nova_lista = cria_lista();

	no* atuali = esq, *atualj = meio->prox;
	while(atuali != meio->prox && atualj != dir->prox){
		if(atuali->valor <= atualj->valor){
			append(atuali->valor, nova_lista);
			atuali = atuali->prox;
		}	
		else{
			append(atualj->valor, nova_lista);
			atualj = atualj->prox;
		}
	}

	while(atuali != meio->prox){
		append(atuali->valor, nova_lista);
		atuali = atuali->prox;
	}
	while(atualj != dir->prox){
		append(atualj->valor, nova_lista);
		atualj = atualj->prox;
	}

	no* atual_ori = esq, *atual_nov = nova_lista->pri;
	while(atual_nov){
		atual_ori->valor = atual_nov->valor;
		atual_ori = atual_ori->prox;
		atual_nov = atual_nov->prox;
	}
	free_lista(nova_lista);
}

void merge_sort(lista* list,no* esq, no* dir){//nao precisa da lista, apenas para vizualizacao
	if(esq == dir) return;

	no* slow, *fast;
	slow = esq; fast = esq;

	while(fast != dir){
		fast = fast->prox;
		if(fast != dir){
			fast = fast->prox;
			slow = slow->prox;
		}
	}

	merge_sort(list,esq, slow);
	merge_sort(list,slow->prox, dir);
	merge(esq, slow, dir);
	print_lista(list);
}

int main(){
	lista* my_list = cria_lista();

	int n; scanf("%d", &n);
	for(int i=0; i<n; i++){
		int b; scanf("%d", &b);
		append(b, my_list);
	}
	print_lista(my_list);

	merge_sort(my_list,my_list->pri,my_list->ultimo);
	//print_lista(my_list);

	free_lista(my_list);

	return 0;
}
