#include <stdio.h>

int ehMultiplo3e5(int x){
    if(!(x%15)) {
        return 1;
    }
    return 0;
}

int main(){

    int x; scanf("%d", &x);
    if(ehMultiplo3e5(x)) printf("%d eh multiplo de 3 e 5\n", x);
    else printf("%d nao eh multiplo de 3 e 5\n", x);


    return 0;
}