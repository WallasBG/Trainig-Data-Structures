#include <stdio.h>
#include <string.h>

int main(){
	int idade;
	char classificacao[30];
	int acompanhado;

	scanf("%d", &idade);
	scanf("%s", classificacao);
	scanf("%d", &acompanhado);

	// if (!strcmp(classificacao,"livre")) printf("sim\n");
	// else if (strcmp(classificacao,"violento") && idade >= 14) printf("sim\n");
	// else if (acompanhado && !(idade < 14)) printf("sim\n");
	// else if (idade >= 16) printf("sim\n");
	// else printf("não\n");

	int livre = !strcmp("livre", classificacao), moderado = !strcmp("moderado", classificacao);

	if ( (livre || idade>=16)|| (idade>=14 &&(moderado || acompanhado)) ) {
		printf("sim\n");
		} else {
		printf("nao\n");
	}

	//msm q

	if ( (!livre && idade<16)&& (idade<14 ||(!moderado && !acompanhado)) ) {
		printf("nao\n");
		} else {
		printf("sim\n");
	}

	return 0;
}