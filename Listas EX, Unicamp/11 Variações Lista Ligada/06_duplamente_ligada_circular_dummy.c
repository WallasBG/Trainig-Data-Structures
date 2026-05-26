#include <stdio.h>
#include <stdlib.h>

typedef struct no * p_no;

typedef struct no{
    int dado;
    p_no ant;
    p_no prox;
}no;

p_no cria_lista(){
    p_no dummy = malloc(sizeof(no));
    if(!dummy) return NULL;

    dummy->ant = dummy;
    dummy->prox = dummy;
    return dummy;
}

p_no cria_no(int valor){
    p_no novo = malloc(sizeof(no));
    if(!novo) return NULL;

    novo->dado = valor;
    novo->ant = NULL; novo->prox = NULL;
    return novo;
}

void add(p_no dummy, int valor){
    p_no novo = cria_no(valor);
    
    novo->prox = dummy->prox;
    dummy->prox->ant = novo;
    novo->ant = dummy;
    dummy->prox = novo;
}

void append(p_no dummy, int valor){
    p_no novo = cria_no(valor);

    novo->prox = dummy;
    novo->ant = dummy->ant;
    dummy->ant->prox = novo;
    dummy->ant = novo;
}

void remocao(p_no dummy, p_no no){
    if(no == dummy) return;

    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    free(no);
}

void imprimi(p_no dummy){
    p_no atual = dummy->prox;
    while(atual != dummy){
        printf("%d ", atual->dado);
        atual = atual->prox;
    }printf("\n");
}

void imprimi_inverso(p_no dummy){
    p_no atual = dummy->ant;
    while(atual != dummy){
        printf("%d ", atual->dado);
        atual = atual->ant;
    }printf("\n");
}

void destroi(p_no dummy){
    p_no atual = dummy->prox, proximo = NULL;
    while(atual != dummy){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(dummy);
}

int main(){

    p_no dummy = cria_lista();

    for(int i=0; i<4; i++) add(dummy,i);
    imprimi(dummy);
    imprimi_inverso(dummy);printf("\n");

    for(int i=-1; i>=-3; i--) append(dummy, i);
    imprimi(dummy);
    imprimi_inverso(dummy);printf("\n");

    remocao(dummy, dummy->ant);//removendo ultimo
    imprimi(dummy);
    imprimi_inverso(dummy);printf("\n");

    remocao(dummy, dummy->prox);//removendo primeiro
    imprimi(dummy);
    imprimi_inverso(dummy);printf("\n");

    remocao(dummy, dummy->prox->prox->prox);//removendo no meio
    imprimi(dummy);
    imprimi_inverso(dummy);

    destroi(dummy);

    return 0;
}