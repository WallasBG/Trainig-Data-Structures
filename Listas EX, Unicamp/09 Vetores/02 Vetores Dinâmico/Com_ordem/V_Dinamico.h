#ifndef V_DINAMICO_H
#define V_DINAMICO_H

struct vetor{
    int *dados;
    int capacidade;
    int n;
};
typedef struct vetor * p_vetor;

p_vetor criar_vetor_vazio(int capacidade);

void destruir_vetor(p_vetor v);

void adicionar_elemento(p_vetor v, int valor);

void remover_elemento_na_posicao(p_vetor v, int posicao);

int buscar(p_vetor v, int valor);

void imprimir(p_vetor v);

#endif