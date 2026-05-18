#include <stdio.h>

int exp_bin(int a, int n){
	if(n == 0) return 1;
	int acc_pot = a, result=1;

	while(n>=1){
		if(n%2) result *= acc_pot;
		acc_pot *= acc_pot;
		n /= 2;
	}

	return result;
}

int main(){
	int exp = exp_bin(2,0);
	printf("ans %d\n\n", exp);

	exp = exp_bin(2,1);
	printf("ans %d\n\n", exp);

	exp = exp_bin(2,10);
	printf("ans %d\n\n", exp);

	exp = exp_bin(2,11);
	printf("ans %d\n", exp);

	return 0;
}

/*
Essa eh a versao iterativa da exponenciacao rapida, tambem chamada de exponenciacao binaria, pois:

a^10, 10 = 1010 = 1*2³ + 0*2² + 1*2¹ + 0*2⁰; Logo a^(2³ + 2¹) = a^(8 + 2) = a⁸ * a²
Soh escrevemos o expoente como binario.

Perceba que o exponte eh escrito como algo do tipo: ...+2⁴+2³+2²+2¹+2⁰
e daí a^(...+16+8+4+2+1) = ...*a^(16) * a⁸ * a⁴ * a² * a¹
Assim o a^n vai ser composto por multiplicacoes dele mesmo.

EX: para chegar em a⁸, começamos com a, depois a*a=a², aí a²*a² = a⁴ e por fim a⁴*a⁴ = a⁸.

Mas obs q no primeiro exemplo com expoente 10, nao podemos multiplicar todas essas potencias de a.
Temos q selecionar quais potencias devem entrar, e quem diz isso eh o nosso proprio exponte em binario.

Aq vamos dividindo o expoente por 2 e verificando o resto para saber se a potencia deve ou nao entrar,
de certa forma estamos transformando o expoente em bin.

E se temos 1110 e precisamos verificar se a proxima potencia entra, basta perceber q
1110 = 14 e 111 = 7, se deslocar da direita para esquerda eh o mesmo q fazer uma divisao inteira por 2,
por isso vamos atualizando o n.

Esse tmb eh um alg com ordem de grandeza O(log(2)), por sempre ir dividindo o expoente por 2.

*/