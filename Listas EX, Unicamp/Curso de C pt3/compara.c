#include <stdio.h>

int compara(char *str1, char *str2){
    for(int i=0; str1[i] != '\0' || str2[i] != '\0'; i++){
        if(str1[i] != str2[i]) return str1[i] - str2[i]; 
    }
    return 0;
}
/* i++ ocorre depois de verificar a condicao, entao ele deixa passar quando str1 ou str2 chegam ao final,
isso permite a verificacao de strings de tamanhos difentes, e retornando a distancia, q nesse caso eh o 
num do primeiro caracter a mais, podendo ser negativo ou positivo*/

int main(){
    printf("%d\n",compara("ABC ","ABC"));

    return 0;
}