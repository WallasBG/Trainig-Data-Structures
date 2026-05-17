#include <stdio.h>

void print_vetor(int* v, int n){
	for(int i=0; i<n; i++)printf("%d ", v[i]);
	printf("\n");
}

void trocar(int* a, int* b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

int particao(int* v, int esq, int dir){
	int pos = dir+1, pivo = v[esq];
	for(int i=dir; i>=esq; i--){
		if(v[i]>=pivo){
			pos--; trocar(&v[i],&v[pos]);
		}
	}
	return pos;
}

/*O pior caso do quick normal é o caso onde o vetor está ordenado, pois o pivo (o cara da esquerda) ja esta na posicao correta
e oseu lado esquerdo esta vazio, entao na pratica é como se estivesse ordenando um elemento por vez, voltando aos alg anteriores(bubble,
insertion, selection) que sao O(n²), saimos de nlog(n) para n²

para resolver isso vamos, mudar a forma q escolhemos o pivo, mas escolher o pivo medio, em relacao ao elemnto do inicio, meio e fim. 
Faremos uma mediana*/

void quick3(int* v, int esq, int dir){
	if(esq<dir){
		int mei=(esq+dir)/2;
		trocar(&v[mei], &v[esq+1]);		

		if(v[esq]>v[dir]) 
			trocar(&v[esq], &v[dir]);
		//logo agr, v[esq]<=v[dir]
		if(v[esq]>v[esq+1]) 
			trocar(&v[esq], &v[esq+1]);
		//logo agr, v[esq]<=v[mei]
		if(v[esq+1]>v[dir]) 
			trocar(&v[esq+1], &v[dir]);
		//logo agr, v[mei]<=v[dir]

	//Assim temos: v[esq]<=v[mei]<=v[dir]
	/*Agr sabemos q v[mei] eh o cara do meio em relacao a v[esq] e v[dir], entao v[mei] sera um bom pivo, e como v[esq] eh menor 
	q v[mei] e ja esta a sua esquerda, nao precisamos coloca-lo na funcao de particao. O mesmo ocorre para v[dir], q eh maior q v[mei] 
	e ja esta a sua direita.

	Como nossa funcao de particao utiliza o primeiro elemento a esq como pivo, por isso mudamos v[mei] para v[esq+1].
	Lembrando q v[esq] n tem necessidade de entrar na funcao entao o primeiro elemento sera v[esq+1]

	O pq de fazer essa troca no inicio eh para evitar caso como [1 2] onde ele passaria inicialmente por todos os if's e dps sofreria a 
	troca de 1 com 2 -> [2 1] e na chamada do particao n iria satisfazer o range do i, e entao iria ficar [2 1] resultando numa n ordenacao.
	Entao solucao para isso, colocamos o v[mei] logo no local q deveria, e os 3 if vao decidir se está correto ou nao.
	Perceba q so ocore com vetor de 2 elementos, mas enfim... 
	*/

		int pos_pivo = particao(v, esq+1, dir-1);
		print_vetor(v,6);
		quick3(v, esq, pos_pivo-1);
		quick3(v, pos_pivo+1, dir);
	}

}




int main(){
	// int v[] = {1,2,3,4,5,6};
	// quick3(v,0,5);

	int v2[] = {8,7,5,4,3,6};
	quick3(v2,0,5);

	return 0;
}