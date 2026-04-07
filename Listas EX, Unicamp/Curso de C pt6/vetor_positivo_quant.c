#include <stdio.h>
#include <stdlib.h>

int *positivos(int *v, int n, int *tam_posi){
    int *ans = (int*) malloc(n * sizeof(int));
    if(!ans) return NULL;

    *tam_posi = 0;

    for(int i=0; i<n; i++){
        if(v[i] > 0){
            ans[*tam_posi] = v[i];
            (*tam_posi)++;
        } 
    }

    return ans;
}

int main(){
    int tam_posi;
    int v[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};

    int *p = positivos(v, 10, &tam_posi);

    for(int i=0; i<tam_posi; i++){
        printf("%d ", p[i]);
    }printf("\n");

    free(p);

    return 0;
}