#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

struct no {
	int chave;
	no *esq, *dir; //pode ter o pai, ajuda nas funcoes de encontrar sucessor e antecessor
	no *pai;
};

no *cria_no(int chave){
	no *novo = malloc(sizeof(no));
	novo->chave = chave;
	novo->esq = novo->dir = NULL;
	return novo;
}

no *criar_arvore(){
	return NULL;
}

void destruir_arvore(no *raiz){//pensa um pouco em como era feito nas listas ligadas, recursivamente
	if(raiz){
		destruir_arvore(raiz->esq);
		destruir_arvore(raiz->dir);
		free(raiz);
	} 
}

no *inserir(no *raiz, int chave){
	if(!raiz){
		no *novo = cria_no(chave);
		return novo;
	}

	if(chave > raiz->chave) raiz->dir = inserir(raiz->dir,chave);
	if(chave < raiz->chave) raiz->esq = inserir(raiz->esq,chave);
	return raiz;
}

no *buscar(no *raiz, int chave){
	if(!raiz || raiz->chave == chave) return raiz;

	if(chave > raiz->chave) return buscar(raiz->dir, chave);
	if(chave < raiz->chave) return buscar(raiz->esq, chave);
}

no *buscar_iterrativo(no *raiz, int chave){
	while(raiz && raiz->chave != chave){
		if(chave > raiz->chave) raiz = raiz->dir;
		else if(chave < raiz->chave) raiz = raiz->esq;
	}
	return raiz;
}

no *minimo(no *raiz){//toda esquerda
	if(!raiz || !raiz->esq) return raiz;
	return minimo(raiz->esq);
}

no *maximo(no *raiz){//toda direita
	if(!raiz || !raiz->dir) return raiz;
	return maximo(raiz->dir);
}

no *ancestral_direita(no *x){
	if(!x) return NULL;
	no *atual = x->pai;

	while(atual && atual->chave < x->chave)
		atual = atual->pai;
	return atual;
}

no *ancestral_direita_rec(no *x){
	if(!x) return NULL;
	if(!x->pai || x->pai->esq == x) return x->pai;
	return ancestral_direita_rec(x->pai);
}//recurcivo, ancestral_direita

no *ancestral_direita_semPAI(no *raiz, no *x){
	no *pai_dir = NULL;
	while(raiz != x){
		if(x->chave > raiz->chave) raiz = raiz->dir;
		else{
			pai_dir = raiz;
			raiz = raiz->esq;
		}
	}
	return pai_dir;
}//ancestral direita sem usar ponteiro pai

no *sucessor(no *x){//se estivessimos utilizando o no pai
	if(x->dir) return minimo(x->dir);
	else return ancestral_direita(x);
}

no *sucessor_sem_NOpai(no *raiz, no *x){
	if(x->dir) return minimo(x->dir);
	return ancestral_direita_semPAI(raiz, x);
}

no *ancestral_esquerda_semPAI(no *raiz, no *x){
	no *pai_esq = NULL;

	while(raiz != x){
		if(x->chave > raiz->chave){
			pai_esq = raiz;
			raiz = raiz->dir;
		}
		else raiz = raiz->esq;
	}
	return pai_esq;
}

no *antecessor_sem_NOpai(no *raiz, no *x){
	if(x->esq) return maximo(x->esq);
	return ancestral_esquerda_semPAI(raiz,x);
}

no *remover(no *raiz, int chave){
	if(!raiz) return NULL;
	if(raiz->chave == chave){
		if(raiz->esq && raiz->dir){//2 filhos
			no *min = minimo(raiz->dir);
			raiz->chave = min->chave;
			raiz->dir = remover(raiz->dir, min->chave);
		}
		else if(raiz->esq){//1 filho a esquerda
			no *aux = raiz->esq;
			free(raiz);
			return aux;
		}
		else{//1 filho a direita ou nao tem filhos (uma folha)
			no *aux = raiz->dir;
			free(raiz);
			return aux;
		}		
	}
	else if(chave > raiz->chave) raiz->dir = remover(raiz->dir, chave);
	else raiz->esq = remover(raiz->esq, chave);
	return raiz;
}/* mostre uma outra forma quando tem 2 filhos, essa versao encontra o no min duas vezes, ele desce duas vezes. Entao seria melhor
aproveitar q ja iria descer para encontrar o min, ja vinha salvando o pai, assim quando encontrasse o min, jah organizava a ligacao*/


/*
Quando o no a ser removido tiver dois filhos, no final das contas vai se reduizir ao caso com filho a direita ou sem filhos, pois o
sucessor, o menor na sub arvore direita nao tem filhos a esquerda

A substituicao do valor do no a ser removido pelo valor do menor no a direita funciona, pois dentre os elementos  da sub arvore a direita
todos ja sao maiores do que ele (sucessor), mantem a configuracao da arvore

a remocao de nos com filhos a esquerda sao para casos onde deve remover um no q so tem filhos a esquerda, e segue ideia parecida para nos com
filhos a direita  
*/

void in_ordem(no *raiz){
	if(raiz){
		in_ordem(raiz->esq);
		printf("%d ", raiz->chave);
		in_ordem(raiz->dir);
	}
}

int main(){
	no *oliver = criar_arvore();
	oliver = inserir(oliver, 8);
	oliver = inserir(oliver, 3);
	oliver = inserir(oliver, 13);
	oliver = inserir(oliver, 1);
	oliver = inserir(oliver, 7);
	oliver = inserir(oliver, 10);
	oliver = inserir(oliver, 15);
	oliver = inserir(oliver, 4);
	oliver = inserir(oliver, 12);
	oliver = inserir(oliver, 14);
	oliver = inserir(oliver, 100);
	oliver = inserir(oliver, 5);
	oliver = inserir(oliver, 85);
	in_ordem(oliver);printf("\n");
	printf("min: %d\n", minimo(oliver)->chave);
	printf("max: %d\n", maximo(oliver)->chave);

	no *x = buscar_iterrativo(oliver, 14);
	printf("vlor x: %d\n", x->chave);
	x = buscar(oliver, 10);
	printf("vlor x: %d\n", x->chave);

	//antecessor e sucessor
	no * dumb= sucessor_sem_NOpai(oliver, buscar(oliver, 7));
	printf("sucessor 7 : %d\n", dumb->chave);
	dumb = sucessor_sem_NOpai(oliver, buscar(oliver, 8));
	printf("sucessor 8 : %d\n", dumb->chave);

	dumb = antecessor_sem_NOpai(oliver, buscar(oliver, 85));
	printf("antecessor 85 : %d\n", dumb->chave);
	dumb = antecessor_sem_NOpai(oliver ,buscar(oliver, 7));
	printf("antecessor 7 : %d\n", dumb->chave);

	oliver =  remover(oliver, 15);
	in_ordem(oliver);printf("\n");

	destruir_arvore(oliver);

	return 0;
}