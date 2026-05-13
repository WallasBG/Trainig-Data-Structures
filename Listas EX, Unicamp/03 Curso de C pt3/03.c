#include <stdio.h>

void Mtom(char* string){
	for(int i=0; (string)[i] != '\0'; i++){
		if((string)[i]>=65 && (string)[i]<=90){
			(string)[i] += 32;
		}
		else if((string)[i]>=97 && (string)[i]<=122){
			(string)[i] -= 32;
		}
	}
}

int main(){
	char palavra[10] = "AmiGo";
	Mtom(palavra);
	printf("%s\n", palavra);

	return 0;
}