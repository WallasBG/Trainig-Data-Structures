#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vetor;
    int n;
}vetorEn;

int numINvetor(int num, int *v, int n){
    for(int i=0; i<n; i++){
        if(num == v[i]) return 1;
    }
    return 0;
}

vetorEn intersecao(int *v, int n, int *w, int m){
    int *ans = (int *)malloc((n + m) * sizeof(int)), idx = 0;

    for(int i=0; i<n; i++){
        if(numINvetor(v[i], w, m)) ans[idx++] = v[i];
    }
    vetorEn result; 
    result.n = idx; result.vetor = ans;
    return result;  
}

vetorEn uniao(int *v, int n, int *w, int m){
    int *ans = (int *)malloc(sizeof(int) * (n+m)), idx = 0;

    for(int i=0; i<n; i++){
        *(ans + idx++) = v[i];
    }
    for(int i=0; i<m; i++){
        if(!numINvetor(w[i], ans, idx)) ans[idx++] = w[i];
    }
    vetorEn result;
    result.n = idx; result.vetor = ans;
    return result;
}

vetorEn diff(int *v, int n, int *w, int m){
    int *ans = (int *)malloc(sizeof(int) * (n+m)), idx=0;
    vetorEn inter = intersecao(v,n,w,m); //tah chamando a funcao lembra de liberar

    for(int i=0; i<n; i++){
        if(!numINvetor(v[i], inter.vetor, inter.n)) ans[idx++] = v[i];
    }
    free(inter.vetor);

    vetorEn result; 
    result.n = idx; result.vetor = ans;
    return result;
}

void printConjunto(int *v, int n){//n==0 no good
    int i;

    printf("{");
    for(i=0; i<n-1; i++)printf("%d ", v[i]);
    printf("%d}\n", v[i]);
}


int main(){
    int n; scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++)scanf("%d", &v[i]);

    int m; scanf("%d",&m);
    int w[m];
    for(int i=0; i<m; i++)scanf("%d", &w[i]);

    vetorEn inter = intersecao(v,n,w,m);
    vetorEn uni = uniao(v,n,w,m);
    vetorEn diferenca = diff(v,n,w,m);
    vetorEn diferenca2 = diff(w,m,v,n);

    printf("A = "); printConjunto(v,n);
    printf("B = "); printConjunto(w,m);
    printf("A inter B = "); printConjunto(inter.vetor, inter.n);
    printf("A U B = "); printConjunto(uni.vetor,uni.n);
    printf("A - B = "); printConjunto(diferenca.vetor, diferenca.n);
    printf("B - A = "); printConjunto(diferenca2.vetor, diferenca2.n);

    free(inter.vetor); free(uni.vetor);
    free(diferenca.vetor); free(diferenca2.vetor);

    return 0;
}