#include <stdio.h>
#include <string.h>

void reverse(char *str){
    int tam = strlen(str)-1;

    for(int i=0; i<=tam/2; i++){
        char aux = str[i];
        str[i] = str[tam-i];
        str[tam-i] = aux;
    }
}

int main(){
    char str[100] = "breath";
    reverse(str);
    printf("%s\n", str);

    return 0;
}