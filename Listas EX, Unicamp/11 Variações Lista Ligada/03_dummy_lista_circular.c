#include <stdio.h>
#include <stdlib.h>

typedef struct no * p_no;

typedef struct no{
    int dado;
    p_no prox;
}no;

p_no cria_lista_circular(){
    p_no dummy = malloc(sizeof(no));
    dummy->prox = dummy;

    return dummy;
}

p_no cria_no(int valor){
    p_no novo = malloc(sizeof(no));
    if(!novo) return NULL;

    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

void add_circular(p_no dummy, int valor){
    p_no novo = cria_no(valor);
    novo->prox = dummy->prox;
    dummy->prox = novo;
}

// p_no append_circular(p_no lista, int valor){
//     p_no novo = cria_no(valor);
//     novo->prox = lista->prox;
//     lista->prox = novo;

//     return novo;
// }
//perdi o append

void remover_circular(p_no dummy, p_no no){
    p_no ant = NULL;

    //caso O(1), remover o primeiro
    if(no == dummy->prox) ant = dummy;

    else{//caso O(n), nao sei o anterior ao no
        ant = no->prox;
        while(ant->prox != no) ant = ant->prox;
    }
    
    ant->prox = no->prox;
    free(no);
} 

void imprimir_circular(p_no dummy){
    if(dummy->prox != dummy){
        p_no atual = dummy->prox;
        while(atual != dummy){
            printf("%d ", atual->dado);
            atual = atual->prox;
        }
    }
    printf("\n");
}

int main(){
    p_no dummy_circ = cria_lista_circular();
    add_circular(dummy_circ, 1);
    add_circular(dummy_circ, 2);
    add_circular(dummy_circ, 3);
    add_circular(dummy_circ, 4);
    imprimir_circular(dummy_circ);

    p_no terceiro = dummy_circ->prox->prox->prox;
    remover_circular(dummy_circ, terceiro);
    imprimir_circular(dummy_circ);

    remover_circular(dummy_circ, dummy_circ->prox);
    imprimir_circular(dummy_circ);

    remover_circular(dummy_circ, dummy_circ->prox->prox);
    imprimir_circular(dummy_circ);

    return 0;
}