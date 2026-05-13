#include <stdio.h>

int fac(int n){
	if(!n) return 1;
	return n*fac(n-1);
}

int main(){
	printf("%d\n", fac(5));
	printf("%d\n", fac(2));
	printf("%d\n", fac(0));

	return 0;
}