#include <stdio.h>

void copia(char *str1, char *str2){
    int i=0;
    while(1){
        if(str1[i] == '\0') break;
        str2[i] = str1[i]; i++;
    }
    str2[i] = '\0';
}

int main(){
    char str1[100] = "breath", str2[100];

    copia(str1,str2);
    printf("%s\n",str1);
    printf("%s\n",str2);

    return 0;
}