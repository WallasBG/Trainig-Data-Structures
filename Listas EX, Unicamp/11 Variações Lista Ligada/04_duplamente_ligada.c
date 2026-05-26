#include <stdio.h>
#include <stdlib.h>

typedef struct no * p_no;

typedef struct no{
    int dado;
    p_no ant;
    p_no prox;
}no;

p_no cria_lista(){
    return NULL;
}

p_no cria_no(int valor){
    p_no novo = malloc(sizeof(no));
    if(!novo) return NULL;

    novo->dado = valor;
    novo->ant = NULL; novo->prox = NULL;
    return novo;
}

p_no adicionar(p_no lista, int valor){
    p_no novo = cria_no(valor);

    if(!lista){
        novo->prox = lista;
        novo->ant = lista;
    }
    else{
        novo->prox = lista;
        novo->ant = lista->ant;
        lista->ant = novo;
    }
    lista = novo;
    return lista;
}
void imprimir(p_no lista){
    p_no atual = lista;

    while(atual){
        printf("%d ", atual->dado);
        atual = atual->prox;
    }printf("\n");
}
void imprimir_inverso(p_no ultimo){
    p_no atual = ultimo;

    while(atual){
        printf("%d ", atual->dado);
        atual = atual->ant;
    }printf("\n");
}

p_no remover_no(p_no lista, p_no no){//agr O(1)
    if(no == lista){
        no->prox->ant = no->ant;
        lista = no->prox;
    }
    else if(no->prox == NULL){
        no->ant->prox = no->prox;
    }
    else{
        no->ant->prox = no->prox;
        no->prox->ant = no->ant;
    }
    free(no);
    return lista;
}

int main(){
    p_no lista = cria_lista(), last;
    lista = adicionar(lista, 10);
    last = lista;
    lista = adicionar(lista, 12);
    lista = adicionar(lista, 13);
    lista = adicionar(lista, 14);

    imprimir(lista);
    imprimir_inverso(last);printf("\n");

    p_no save = last->ant;
    lista = remover_no(lista, last);
    imprimir(lista);
    imprimir_inverso(save);printf("\n");

    lista = remover_no(lista, lista);
    imprimir(lista);
    imprimir_inverso(save);printf("\n");

    lista = adicionar(lista, -1);
    imprimir(lista);
    imprimir_inverso(save);printf("\n");

    lista = remover_no(lista, lista->prox);
    imprimir(lista);
    imprimir_inverso(save);

    return 0;
}