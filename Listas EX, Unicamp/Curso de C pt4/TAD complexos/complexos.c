//implementação
#include "complexos.h"
#include <math.h>

complexo complexo_novo(float real, float imag){
    complexo novo;
    novo.real = real; novo.img = imag;

    return novo;
}

complexo complexo_soma(complexo a, complexo b){
    complexo result;
    result.real = a.real + b.real;
    result.img = a.img + b.img;

    return result;
}

double complexo_absoluto(complexo a){
    return sqrt(a.real*a.real + a.img*a.img);
}

complexo complexo_le(){
    complexo novo;
    scanf("%f %f", &novo.real, &novo.img);

    return novo;
}

void complexo_imprime(complexo a){
    printf("%.2f %+.2fi\n", a.real, a.img);
}

int complexos_iguais(complexo a, complexo b){
    if(a.img == b.img && a.real == b.real) return 1;
    return 0;
}

complexo complexo_multiplicacao(complexo a, complexo b){
    complexo result;
    result.real = a.real * b.real;
    result.img = a.img * b.img;

    return result;
}

complexo complexo_conjugado(complexo a){
    complexo conjugado;
    conjugado.img = a.img*-1;

    return conjugado;
}