#include <stdio.h>
#include <stdlib.h>

int main(){
	int *notas = (int *)malloc(5*sizeof(int));
	float media2=0.0;

	//notas[0] = 1; notas[1] = 2; notas[2] = 3; notas[3] = 4; notas[4] = 5;

	for(int i=0; i<5; i++){
		scanf("%d", &notas[i]);
	}

	for(int i=0; i<5; i++){
		media2 += (float) *(notas+i) /5;
	}

	printf("media2: %.2f\n", media2);

	return 0;
}