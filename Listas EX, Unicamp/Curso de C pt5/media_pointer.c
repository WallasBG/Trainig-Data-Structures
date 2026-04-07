#include <stdio.h>
#include <stdlib.h>

int main(){
	int *notas = (int *)malloc(5*sizeof(int));
	if(notas == NULL) exit(1); //Nao alocou nada

	float media=0.0;

	//notas[0] = 1; notas[1] = 2; notas[2] = 3; notas[3] = 4; notas[4] = 5;

	for(int i=0; i<5; i++) scanf("%d", &notas[i]);
	for(int i=0; i<5; i++) media += (float) *(notas+i) /5;
	free(notas);

	printf("media: %.2f\n", media);

	return 0;
}