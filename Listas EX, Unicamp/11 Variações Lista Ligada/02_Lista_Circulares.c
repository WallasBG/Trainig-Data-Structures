#include <stdio.h>
#include <stdlib.h>

typedef struct no * p_no;

typedef struct no{
    int dado;
    p_no prox;
}no;

p_no cria_lista_circular(){
    return NULL;
}

p_no cria_no(int valor){
    p_no novo = malloc(sizeof(no));
    if(!novo) return NULL;

    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

p_no add_circular(p_no lista, int valor){
    p_no novo = cria_no(valor);

    if(!lista){//vazio
        novo->prox = novo;
        lista = novo;
    }
    else{//lista->prox eh o primeiro no
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return lista;
}

p_no append_circular(p_no lista, int valor){
    p_no novo = cria_no(valor);

    if(!lista){
        novo->prox = novo;
        lista = novo;
    }

    else{
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return novo;
}

p_no remover_circular(p_no lista, p_no no){
    if(no->prox == no){//lista de um elemento
        free(no); return NULL;
    }

    p_no ant = NULL;

    //caso O(1), remover o primeiro
    if(no == lista->prox) ant = lista;

    else{//caso O(n), nao sei o anterior ao no
        ant = no->prox;
        while(ant->prox != no) ant = ant->prox;
    }
    
    if(no == lista) lista = ant;//se for remover o ultimo
    ant->prox = no->prox;
    free(no);
    return lista;
} 

void imprimir_circular(p_no lista){
    if(lista){
        p_no atual = lista->prox;//primeiro no
    
        do{
            printf("%d ", atual->dado);
            atual = atual->prox;                
        } while (atual != lista->prox);
        //usando do while para imprimir tambem listas de soh um elemento
    }
    printf("\n");
}

void imprimir_circular_bool(p_no lista){//outra forma so no while
    p_no atual = lista->prox;
    int imprimiu_a_pri = 0;

    while(atual != lista->prox || !imprimiu_a_pri){
        printf("%d ", atual->dado);
        atual = atual->prox;
        imprimiu_a_pri = 1;
    }printf("\n");
}

int main(){
    p_no l_c = cria_lista_circular();

    for(int i=0; i<5; i++){
        int a; scanf("%d", &a);
        l_c = add_circular(l_c, a);
    }
    imprimir_circular(l_c);
    imprimir_circular_bool(l_c);

    p_no pri = l_c->prox;
    l_c = remover_circular(l_c, pri);
    printf("\n"); imprimir_circular(l_c);

    p_no ultm = l_c;
    l_c = remover_circular(l_c, ultm);
    printf("\n"); imprimir_circular(l_c);

    l_c = remover_circular(l_c, l_c->prox);
    l_c = remover_circular(l_c, l_c->prox);
    printf("\n"); imprimir_circular(l_c);
    imprimir_circular_bool(l_c);

    l_c = remover_circular(l_c, l_c);
    printf("\n"); imprimir_circular(l_c);

    for(int i=0; i<5; i++){
        int a; scanf("%d", &a);
        l_c = append_circular(l_c, a);
    }
    imprimir_circular_bool(l_c);

    return 0;
}