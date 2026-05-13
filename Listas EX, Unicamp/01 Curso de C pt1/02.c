#include <stdio.h>

int quanti_dig(int num){
    int mult_dez = 1, cont=1;

    while(1){
        int div = num/mult_dez;
        if (div>9){
            cont++;
            mult_dez *= 10;
        }
        else break;
    }

    return cont;
}

int potencia(int num, int pot){
	int mult = 1;

	for(int i=0; i<pot; i++){
		mult *= num;
	}
	return mult;
}

int eh_palindromo(int num){
    int quant_dig = quanti_dig(num);
	int original = num, final = 0, exp = quant_dig-1;


	for(int i=0; i<quant_dig; i++){
		final += (num%10) * potencia(10,exp);
		num /= 10; exp--;
	}

	printf("original: %d, invertido: %d\n", original, final);
	if(original == final) return 1;
	return 0;

}

int main(){
	int num; scanf("%d",&num);

	if(eh_palindromo(num)) printf("eh palindromo\n");
	else printf("n n eh\n");

    // if(eh_palindromo(102)) printf("eh palindromo\n");
    // eh_palindromo(102);
    return 0;
}