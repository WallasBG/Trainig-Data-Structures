#include <stdio.h>

char cifraCezar(int k, char C){
	int dist_AtoC = C - 'A';// Mapeia as letras de A - Z entre 0 e 25
	int dist_AtoEncrip = ((dist_AtoC) + k) % 26;

	// printf("Sua letra %c eh pos %d\n", C, dist_AtoC);
	// printf("Sua letra %c encripitada eh pos %d\n", 'A' + dist_AtoEncrip, dist_AtoEncrip);

	return 'A' + dist_AtoEncrip;
}

char DecifraCezar(int k, char C){
	int dist_AtoC = C - 'A';// Mapeia as letras de A - Z entre 0 e 25
	int dist_AtoEncrip = (dist_AtoC + (26-k))%26; //26-k devolve a distancia da letra original ate a encriptada
	//com ela em maos, basta pegar a a posico da letra encriptada e percorrer essa distancia

	return 'A' + dist_AtoEncrip;
}


int main(){
	//Encriptar palavras
	int k;
	char palavra[100], palavra_encript[100];
	scanf("%d ", &k); scanf("%s", palavra);

	int i=0;
	for(i; palavra[i] != '\0'; i++) palavra_encript[i] = cifraCezar(k,palavra[i]);
	palavra_encript[i] = '\0';
	printf("%s\n", palavra_encript);

	char decifrado[100];
	for(i=0; palavra_encript[i] != '\0'; i++) decifrado[i] = DecifraCezar(k,palavra_encript[i]);
	decifrado[i] = '\0';
	printf("%s\n", decifrado);

	return 0;
}