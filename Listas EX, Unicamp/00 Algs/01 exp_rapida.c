#include <stdio.h>

int exp_rap_rec(int a, int n){
	if(n == 1) return a; 
	if(n == 0) return 1;

	if(!(n%2)){
		int result = exp_rap_rec(a,n/2);
		printf("%d\n", result*result);
		return  result*result; 
	}
	else{
		int result = exp_rap_rec(a,(n-1)/2);
		printf("%d\n", result*result*a);
		return result * result * a;
	}
}

int main(){
	int exp = exp_rap_rec(2,0);
	printf("ans %d\n\n", exp);

	exp = exp_rap_rec(2,1);
	printf("ans %d\n\n", exp);

	exp = exp_rap_rec(2,10);
	printf("ans %d\n\n", exp);

	exp = exp_rap_rec(2,11);
	printf("ans %d\n", exp);
	return 0;
}

//A ideia eh q ao inves de calcular a vezes ele mesmo n vezes, vamos reaproveitar resultados q ja temos.

//Ex: para calcular a.a.a.a.a.a.a.a, podemos calcular a.a.a.a, e perceber q basta multiplicar esse resultado por ele mesmo.
//Poupando de realizar (resultado) * a.a.a.a e de certa forma calcular a.a.a.a novamente.
//dai entra divisao e conquista pois podemos fazer isso para qualquer potencia, no nosso ex a.a.a.a, ainda podemos dividir mais 
//duas vezes, até chegar no caso baso base onde a¹ eh ele mesmo.

//Daí observe q sempre estamos dividindo o trabalho ao meio, log_2(n), resultando em O(log(n)).
//Se o exp for impar, obs q a^(2n+1) = a^2n * a, daí pega o com expoente par e continue a divisao, soh lembrando de carregar esse a 
//solto na multiplicacao.