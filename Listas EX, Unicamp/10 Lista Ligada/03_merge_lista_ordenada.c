#include <stdio.h>
#include <stdlib.h>


typedef struct no * p_no;

typedef struct no{
	int dado;
	p_no prox;
}no;

p_no cria_lista(){
	return NULL;
}

p_no cria_no(int valor){
	p_no novo = malloc(sizeof(no));
	if(!novo) return NULL;

	novo->dado = valor;
	novo->prox = NULL;
}

p_no append(p_no lista, p_no* tail,int valor){
	p_no novo = cria_no(valor);

	if(!lista){
		novo->prox = lista;
		lista = novo;
		*tail = novo;
	}
	else{
		novo->prox = (*tail)->prox;
		(*tail)->prox = novo;
		*tail = novo;
	}
	return lista;
}

p_no merge(p_no lista1, p_no lista2){
	p_no lista_nova = cria_lista();
	p_no tail_nova = lista_nova;

	p_no atualL1 = lista1, atualL2 = lista2;

	while(atualL1 && atualL2){
		if(atualL1->dado <= atualL2->dado){
			lista_nova = append(lista_nova, &tail_nova, atualL1->dado);
			atualL1 = atualL1->prox;
		}
		else{
			lista_nova = append(lista_nova, &tail_nova, atualL2->dado);
			atualL2 = atualL2->prox;
		}		
	}

	while(atualL1){
		lista_nova = append(lista_nova, &tail_nova, atualL1->dado);
		atualL1 = atualL1->prox;
	}
	while(atualL2){
		lista_nova = append(lista_nova, &tail_nova, atualL2->dado);
		atualL2 = atualL2->prox;
	}

	return lista_nova;
}

void imprimi(p_no lista){
	if(lista){
		printf("%d ", lista->dado);
		imprimi(lista->prox);
	}
	else printf("\n");
}

void destruir(p_no lista){
	if(lista){
		destruir(lista->prox);
	}
	free(lista);
}

int main(){
	p_no l1 = cria_lista(), l2 = cria_lista();
	p_no taiL1 = l1, taiL2 = l2;

	l1 = append(l1, &taiL1, 1);
	l1 = append(l1, &taiL1, 3);
	l1 = append(l1, &taiL1, 4);
	imprimi(l1);

	l2 = append(l2, &taiL2, -1);
	l2 = append(l2, &taiL2, 0);
	l2 = append(l2, &taiL2, 5);
	imprimi(l2);

	p_no lista_nova = merge(l1, l2);
	imprimi(lista_nova);

	destruir(l1);
	destruir(l2);
	destruir(lista_nova);
	
	return 0;
}