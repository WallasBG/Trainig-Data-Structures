//percorrendo no em largura
//tem q usar fila, vou uzar fila de vetores, nao circulur, o mais simples

#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

struct no{
    int valor;
    no *esq, *dir;
};

typedef struct fila{
    no **v;
    int ini, fim, capacidade;
}fila;

fila *cria_fila(int capacidade){
    fila *f = malloc(sizeof(fila));
    f->capacidade = capacidade;

    f->v = malloc(f->capacidade * sizeof(no*));
    f->ini = f->fim = 0;
    return f;
}

void enfileirar(no *raiz, fila *f){
    f->v[f->fim++] = raiz;
}

no *desenfileira(fila *f){
    return f->v[f->ini++];
}

void percorrendo_largura(no *raiz){
    fila *f = cria_fila(100);
    no *r = raiz;
    
    enfileirar(r,f);
    while(f->ini < f->fim){
        r = desenfileira(f);
        if(r->esq) enfileirar(r->esq,f);
        if(r->dir) enfileirar(r->dir,f);

        printf("%d ", r->valor);
        
    }
    printf('\n');
}

int main(){

    return 0;
}