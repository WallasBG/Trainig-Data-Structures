#include <stdio.h>
#include "complexos.h"

int main(){

    complexo a = complexo_le();
    complexo b = complexo_novo(11.22,9);

    printf("cpx a: "); complexo_imprime(a);
    printf("cpx b: "); complexo_imprime(b);

    printf("absoluto de a: %.2lf\n",complexo_absoluto(a));

    complexo soma = complexo_soma(a,b); 
    printf("a + b: "); complexo_imprime(soma);

    complexo mult = complexo_multiplicacao(a,b); 
    printf("a * b: "); complexo_imprime(mult);

    complexo conj_soma = complexo_conjugado(soma); 
    printf("conjugado da soma: "); complexo_imprime(conj_soma);

    return 0;
}
