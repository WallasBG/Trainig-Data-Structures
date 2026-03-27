#include <stdio.h>

char cifraCezar(int k, char C){
	int dist_AtoC = C - 'A';// Mapeia as letras de A - Z entre 0 e 25
	int dist_AtoEncrip = ((dist_AtoC) + k) % 26;

	printf("Sua letra %c eh pos %d\n", C, dist_AtoC);
	printf("Sua letra %c encripitada eh pos %d\n", 'A' + dist_AtoEncrip, dist_AtoEncrip);

	return 'A' + dist_AtoEncrip;

}

int main(){
	// so botar os esquemas para receber do teclado. ai cuidado com o espaco pos scanf///

	// faz um de cifras so pra complementar


	char encript = cifraCezar(3,'C');
	printf("\n%c\n", encript);

	return 0;
}