#include <stdio.h>
#include <stdlib.h>

typedef struct no * p_no;

typedef struct no{
    int exp;
    double coeficiente;
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

p_no cria_no(int exp, double coeficiente){
    p_no novo = malloc(sizeof(no));
    if(!novo) return NULL;

    novo->exp = exp;
    novo->coeficiente = coeficiente;
    novo->ant = NULL; novo->prox = NULL;
    return novo;
}

void add_ordenado(p_no dummy, int exp, double coeficiente){
    p_no novo = cria_no(exp, coeficiente);
    p_no atual = dummy->ant;

    while(atual != dummy && novo->exp < atual->exp) atual = atual->ant;
    novo->ant = atual;
    novo->prox = atual->prox;
    atual->prox->ant = novo;
    atual->prox = novo;
}

// void add(p_no dummy, int valor){
//     p_no novo = cria_no(valor);
    
//     novo->prox = dummy->prox;
//     dummy->prox->ant = novo;
//     novo->ant = dummy;
//     dummy->prox = novo;
// }

// void append(p_no dummy, int valor){
//     p_no novo = cria_no(valor);

//     novo->prox = dummy;
//     novo->ant = dummy->ant;
//     dummy->ant->prox = novo;
//     dummy->ant = novo;
// }

void remocao(p_no dummy, p_no no){
    if(no == dummy) return;

    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    free(no);
}

void imprimi(p_no dummy){
    p_no atual = dummy->prox;
    while(atual != dummy->ant){
        printf("%.2lf X^%d + ", atual->coeficiente, atual->exp);
        atual = atual->prox;
    }
    printf("%.2lf X^%d\n", atual->coeficiente, atual->exp);
}

// void imprimi_inverso(p_no dummy){
//     p_no atual = dummy->ant;
//     while(atual != dummy){
//         printf("%d ", atual->exp);
//         atual = atual->ant;
//     }printf("\n");
// }

void destroi(p_no dummy){
    p_no atual = dummy->prox, proximo = NULL;
    while(atual != dummy){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(dummy);
}

p_no soma_poli(p_no d1, p_no d2){
    p_no soma = cria_lista();
    p_no atual_d1 = d1->prox, atual_d2 = d2->prox;

    while(atual_d1 != d1){
        while(atual_d2 != d2){
            if(atual_d1->exp == atual_d2->exp){
                double coeficiente = atual_d1->coeficiente + atual_d2->coeficiente;
                add_ordenado(soma, atual_d1->exp, coeficiente);
                atual_d2 = atual_d2->prox;
                remocao(d2, atual_d2->ant);
            }
            else atual_d2 = atual_d2->prox;
        }
        atual_d1 = atual_d1->prox;
        atual_d2 = d2->prox;
    }
    while(atual_d2 != d2){
        add_ordenado(soma, atual_d2->exp, atual_d2->coeficiente);
        atual_d2 = atual_d2->prox;
    }
    return soma;
}

int main(){
    p_no polinomio1 = cria_lista();
    add_ordenado(polinomio1,2,10);
    add_ordenado(polinomio1,5,99.11);
    imprimi(polinomio1);

    p_no polinomio2 = cria_lista();
    add_ordenado(polinomio2,1,8);
    add_ordenado(polinomio2,3,12.11);
    add_ordenado(polinomio2,2,2.11);
    add_ordenado(polinomio2,5,58);
    imprimi(polinomio2);

    p_no polinomio_soma = soma_poli(polinomio1, polinomio2);
    imprimi(polinomio_soma);

    return 0;
}