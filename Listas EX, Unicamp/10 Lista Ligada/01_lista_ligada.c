#include <stdio.h>
#include <stdlib.h>

typedef struct no* p_no; //p_no eh ponteiro para no

typedef struct no{
	int dado;
	p_no prox;
}no;

p_no cria_lista(){
	return NULL;
}
//lista no final das contas a lista vai ser soh uma etiqueta, q marca primeiro no

void destruir_lista(p_no h_lista){
	p_no atual = h_lista;
	while(atual){
		p_no proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
}

void destruir_lista_rec(p_no h_lista){
	if(h_lista){
		destruir_lista_rec(h_lista->prox);
		free(h_lista);
	}
}

p_no cria_no(int valor){
	p_no novo = malloc(sizeof(no));
	if(!novo) return NULL;

	novo->dado = valor;
	return novo;
}

p_no adicionar_elemento(p_no h_lista, int valor){
	p_no novo = cria_no(valor);
	novo->prox = h_lista;
	h_lista = novo;

	return h_lista;
}

void imprimir(p_no h_lista){
	for(p_no atual = h_lista; atual; atual = atual->prox){
		printf("%d ", atual->dado);
	}printf("\n");
}

void imprimir_rec(p_no h_lista){
	if(h_lista){
		printf("%d ", h_lista->dado);
		return imprimir_rec(h_lista->prox);
	}
	printf("\n");
}

int main(){

	p_no lista = cria_lista();
	lista = adicionar_elemento(lista, 11);
	lista = adicionar_elemento(lista, 9);
	lista = adicionar_elemento(lista, -1);

	imprimir(lista);
	imprimir_rec(lista);

	//destruir_lista(lista);
	destruir_lista_rec(lista);

	return 0;
}
