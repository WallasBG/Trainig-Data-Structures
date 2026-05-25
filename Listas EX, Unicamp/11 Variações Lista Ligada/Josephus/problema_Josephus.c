#include "lista_circular.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5, m = 2;
    p_no lc = cria_lista_circular();

    for(int i=0; i<n; i++)
        lc = append_circular(lc, i);
    imprimir_circular(lc);

    p_no remover = NULL;
    while(lc->prox != lc){
        for(int i=0; i<m; i++){
            lc = lc->prox;
        }
        remover = lc->prox;
        lc->prox = remover->prox;
        free(remover);

        imprimir_circular(lc);
    }
}