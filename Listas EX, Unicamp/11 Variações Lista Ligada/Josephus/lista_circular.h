#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct no * p_no;

typedef struct no{
    int dado;
    p_no prox;
}no;

p_no cria_lista_circular();

p_no cria_no(int valor);

p_no add_circular(p_no lista, int valor);

p_no append_circular(p_no lista, int valor);

p_no remover_circular(p_no lista, p_no no);

void imprimir_circular(p_no lista);

void imprimir_circular_bool(p_no lista);//outra forma so no while

#endif