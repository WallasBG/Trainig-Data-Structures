#include <stdio.h>

int main(){
    float inicial, mensal, valor_final, juros;
    int meses;

    printf("Depósito inicial: "); scanf("%f", &inicial);
    valor_final = inicial;
    printf("Quantos meses de investimento? "); scanf("%d", &meses);
    printf("Valor para investimento mensal: "); scanf("%f", &mensal);
    printf("Sob qual taxa de juros %% "); scanf("%f", &juros);

    for(int i=0; i<meses; i++){
        valor_final = valor_final * (juros/100) + valor_final;
        valor_final += mensal;
    }

    printf("Seu valor final pos %d meses, %.2f\n", meses, valor_final);

    return 0;
}