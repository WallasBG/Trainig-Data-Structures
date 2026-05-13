#include <stdio.h>

int soma(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x-y;
}

float divisao(int x, int y){
    return (float)x/y;
}

int mult(int x, int y){
    return x*y;
}

int main(){
    int input; scanf("%d", &input);

    if(input == 5) return 0;

    else{
        int x, y; scanf("%d %d", &x, &y);

        if(input == 1) printf("%d + %d = %d\n", x, y, soma(x,y));
        else if(input == 2) printf("%d - %d = %d\n", x, y, sub(x,y));
        else if(input == 3) printf("%d * %d = %d\n", x, y, mult(x,y));
        else printf("%d / %d = %.2f\n", x, y, divisao(x,y));
    }

    return 0;
}