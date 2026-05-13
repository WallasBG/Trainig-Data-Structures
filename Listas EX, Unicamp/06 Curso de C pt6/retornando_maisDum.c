#include <stdio.h>

void min_max(int *v, int tam, int *max, int *min){
    *max = *min = v[0];

    for(int i=1; i<tam; i++){
        if(v[i] > *max) *max = v[i];
        if(v[i] < *min) *min = v[i];
    }
}

int main(){
    int v[100], n, min, max;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    min_max(v, n, &max, &min);
    printf("max %d\nmin %d\n", max, min);

    return 0;
}