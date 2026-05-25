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

p_no busca_rec(p_no lista, int a){
    if(!lista || lista->dado == a) return lista;
    return busca_rec(lista->prox, a);
}

p_no remover(p_no lista, int a){
//a ideia eh ir refazendo as ligacoes

    if(!lista) return NULL;

    if(lista->dado == a){
        p_no proximo = lista->prox;
        free(lista);
        return proximo;
    }

    lista->prox = remover(lista->prox, a);
    return lista;
}

//vamos refazendo as ligacoes ate o momento q encontrar o no q sera removido , ou n (NULL).
//Perceba q se nao for encontrado ocorre o retorno do proprio no, isso para q,
//o no da chamada anterior mantenha a ligacao

//quando encontrar o no desejado marcamos o no a sua direita como proximo. 
//Destruimos o no desejado, e retornamos o proximo. Onde o no da 
//chamada anterior ira se ligar a ele

//dai a funcao vai retornando e de fato agora sim refazendo as ligacoes, e no final teremos 
//acesso a ponta dessa lista

p_no remover_todos(p_no lista, int a){
    if(!lista) return NULL;

    if(lista->dado == a){
        p_no proximo = lista->prox;
        free(lista);
        proximo->prox = remover_todos(proximo->prox,a);
        return proximo;
    }

    lista->prox = remover_todos(lista->prox, a);
    return lista;
}//msm ideia com a diferencao q agr paramos quando chegar ao final da lista, e o cuidado de
//ao remover o no desejado, quem continua a ligacao agora eh o no proximo.


int main(){

	p_no lista = cria_lista();
	lista = adicionar_elemento(lista, 11);
	lista = adicionar_elemento(lista, 9);
	lista = adicionar_elemento(lista, -1);

	imprimir(lista);
	imprimir_rec(lista);

    p_no achei = busca_rec(lista, 9);
    printf("%p, dado: %d\n", achei, achei->dado);
    
    printf("%p\n", busca_rec(lista,3));

    remover(lista,9);//nao eh o primeiro elemento, logo a ponta nao muda
    imprimir_rec(lista);
    lista = remover(lista,-1);
    imprimir_rec(lista);
    remover(lista, 999);
    imprimir_rec(lista);

	//destruir_lista(lista);
	destruir_lista_rec(lista);

    printf("\nLista nova ----\n");
    lista = cria_lista();
    int n; scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        int input; scanf("%d", &input);
        lista = adicionar_elemento(lista, input);
    }printf("\n");
    imprimir(lista);
    printf("\nremover elemento: "); scanf("%d", &n);

    remover_todos(lista, n);
    imprimir_rec(lista);
    destruir_lista(lista);

	return 0;
}
