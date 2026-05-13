#include <stdio.h>

int potencia(int A, int n){
	if(!n) return 1;
	return potencia(A,n-1)*A;
}

int main(){
	printf("%d\n", potencia(2,3));

	return 0;
}