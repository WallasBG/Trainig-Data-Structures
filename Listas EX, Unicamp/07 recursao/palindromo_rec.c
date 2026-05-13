#include <stdio.h>
#include <string.h>

int eh_palindro(char *string, int ini, int fim){
	if(ini>=fim) return 1;

	return string[ini] == string[fim] && eh_palindro(string, ini+1, fim-1);
}

int main(){
	printf("%d\n", eh_palindro("OVO", 0, strlen("OVO")-1));
	printf("%d\n", eh_palindro("OBBO", 0, strlen("OBBO")-1));
	printf("%d\n", eh_palindro("ABC", 0, strlen("ABC")-1));

	return 0;
}