#include <stdio.h>
#define MAX 10000

int ocorre(char texto[], int pos, char padrao[]){
    int i=0;

    while(1){
        if(padrao[i] == '\0') break; //se o padrao acabou, logo nao encontramos diff, deu certo
        if((texto[i] == '\0') || texto[pos + i] != padrao[i] && padrao[i] != '*') return 0;
        i++;
    }

    return 1;
}
void imprime_trecho(char texto[], int start, int tam){
    int i=0;

    while(1){
        if(texto[start + i] == '\0' || i == tam) break;
        printf("%c", texto[start+ i++]);
    }
    printf("\n");
}

int tamanho(char texto[]){
    int count = 0, i = 0;

    while(texto[i++] != '\0') count++;

    return count;
}

int main(){

    ocorre("jijujoutkkjuhhoutnjh", 4, "*out");
    imprime_trecho("jijujoutkkjuhhoutnjh", 4, 10);
    printf("%d\n", tamanho("abc"));

    char texto[MAX]; //scanf("%s", texto);
    fgets(texto, MAX, stdin);// Esse fgets ler até \n, e tambem o armazena, na hora de imprimir ele sai no final

    for(int i=0; texto[i] != '\0'; i++){
        if(ocorre(texto, i, "*os")){
            imprime_trecho(texto, i, tamanho("*os"));
        }
    }


    return 0;
}