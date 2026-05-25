#include <stdio.h>
#include <stdlib.h>

typedef struct no * p_no;

typedef struct no{
    int dado;
    struct no *prox;
}no;

p_no cria_lista(){
	return NULL;
}

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

//-------------copy, invert, concat

p_no copy_rec(p_no lista1){
    if(!lista1) return NULL;

    p_no novo = cria_no(lista1->dado);
    novo->prox = copy_rec(lista1->prox);
    return novo;
}

p_no concat_rec(p_no l1, p_no l2){
    if(!l1) return l2;
    
    l1->prox = concat_rec(l1->prox, l2);
    return l1;
}
/*Antes:
if(!(l1->prox))l1->prox = l2;
else concat_rec(l1->prox, l2);

nao funciona para concatenar lista vazia com outra lista
*/

//Agr vamos ate o null e retornamos a ponta da lista2, dai o no da chamada anterior
// se ligara com a ponta da lista2, e assim por diante de tras pra frente.

p_no invert_rec(p_no lista){
    if( !lista || !(lista->prox) )return lista;

    p_no inicio = invert_rec(lista->prox);
    
    lista->prox->prox = lista;
    lista->prox = NULL;

    return inicio;
}

/* A ideia eh ir até o final da lista e encontrar o ultimo elemento, q será a nova
cabeca, o inicio. Com eles em maos basta soh ter cuidado para nao perdelo, logo verifique
a funcao so retorna esse novo inicio.

apos isso temos ir voltantando e ir invertendo a lista aos poucos. Depois de encontrar o fim, 
o no da chamada anterior será necessaria mente o penutimo elemento, logo vamos fazer o ultimo
apontar ao penultimo, e fazer esse penultimo apontar para null.abort

Logo invertemos um pedaco, voltando a chamada anterior agora lista eh um no q nao eh o penultimo
mas se liga no ultimo elemento da lista nova q esta se formando. Entao por meio de lista 
consigo acessar o ultimo elemento, e faze-lo se ligar a lista q agora sera o ultimo elemento,
para isso faco ele apontar para null.

e o ciclo se repete. 

para lista == null retornamos a propria lista, (jah ta invertida), algo semelhante ocorre
com lista de um elemento.
*/

p_no invert(p_no lista){
    p_no atual = lista, ant = NULL, proximo = atual;

    while(atual){
        proximo = proximo->prox;
        atual->prox = ant;
        ant = atual;
        atual = proximo;
    }

    return ant;
}

int main(){
    p_no l1 = cria_lista();
    
    l1 = adicionar_elemento(l1, 2);
    l1 = adicionar_elemento(l1, 94);
    l1 = adicionar_elemento(l1, 70);
    l1 = adicionar_elemento(l1, 62);
    l1 = adicionar_elemento(l1, 58);
    imprimir(l1);printf("\n");

    p_no l2 = copy_rec(l1);
    imprimir(l2);printf("\n");

    l2 = adicionar_elemento(l2, 22);
    l2 = adicionar_elemento(l2, 26);
    imprimir(l2);printf("\n");

    concat_rec(l1,l2);
    imprimir(l1);printf("\n");

    l1 = invert_rec(l1);
    imprimir(l1);printf("\n");

    l1 = invert(l1);
    imprimir(l1);printf("\n");

    return 0;
}