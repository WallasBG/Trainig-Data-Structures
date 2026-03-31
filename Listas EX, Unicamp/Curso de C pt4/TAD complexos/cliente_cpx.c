#include <stdio.h>
#include "complexos.h"

int main(){

    complexo a = complexo_le();
    complexo b = complexo_novo(11.22,9);
    printf("absoluto de a: %.2lf\n",complexo_absoluto(a));
    complexo soma = complexo_soma(a,b); complexo_imprime(soma);
    complexo mult = complexo_multiplicacao(a,b); complexo_imprime(mult);
    complexo conj_soma = complexo_conjugado(soma); complexo_imprime(conj_soma);

    return 0;
}
