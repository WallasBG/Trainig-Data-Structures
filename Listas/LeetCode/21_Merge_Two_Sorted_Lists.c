#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct{
	struct ListNode *primeiro;
	int tamanho;
}lista;

struct ListNode *node_create(int value){
	struct ListNode *novo_no = (struct ListNode *)malloc(sizeof(struct ListNode));
	if(!novo_no) return NULL;

	novo_no->val = value;
	novo_no->next = NULL;

	return novo_no; 
}

lista* myLinkedListCreate() {
	lista *pt_lista = (lista *)malloc(sizeof(lista));
	if(!pt_lista) return NULL;

	pt_lista->primeiro = NULL;
	pt_lista->tamanho = 0;

	return pt_lista;    
}

void myLinkedListAddAtHead(lista* obj, int val) {//add inicio
	struct ListNode *novo_no = node_create(val);

	novo_no->next = obj->primeiro;
	obj->primeiro = novo_no; 
	obj->tamanho++;    
}

void myLinkedListAddAtTail(lista* obj, int val) {//add final
	if(!obj->primeiro){//lista vazia
		myLinkedListAddAtHead(obj, val);
	}
	else{
		struct ListNode *novo_no = node_create(val);
		struct ListNode *atual = obj->primeiro;
		while(atual->next){
			atual = atual->next;
		}
		atual->next = novo_no;
		obj->tamanho++;
	}    
}

void print_front(lista *obj){
	struct ListNode *atual = obj->primeiro;

	while(atual){
		printf("%d ", atual->val);
		atual = atual->next;
	}
	printf("\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

	if(!list2) return list1;
	else if(!list1) return list2;

	struct ListNode *atual1 = list1, *atual2 = list2, *last = NULL, *head = NULL;
	if(list1->val <= list2->val){
		head = list1;
		atual1 = atual1->next;
	}
	else {
		head = list2;
		atual2 = atual2->next;
	}
	last = head;

	while(atual1 && atual2){
		if(atual1->val <= atual2->val){
			last->next = atual1;
			last = atual1;
			atual1 = atual1->next;
		}
		else{
			last->next = atual2;
			last = atual2;
			atual2 = atual2->next;
		}
	}

	if(!atual1){
		last->next = atual2;	
	}
	else{
		last->next = atual1;
	}
	return head;    
}


int main(){
	lista *pica = myLinkedListCreate();
	myLinkedListAddAtTail(pica, 1);
	myLinkedListAddAtTail(pica, 2);
	myLinkedListAddAtTail(pica, 4);
	print_front(pica);

	lista *poco = myLinkedListCreate();
	myLinkedListAddAtTail(poco, 1);
	myLinkedListAddAtTail(poco, 3);
	myLinkedListAddAtTail(poco, 4);
	print_front(poco);
	struct ListNode *merged = mergeTwoLists(pica->primeiro, poco->primeiro);
	struct ListNode *atual = merged;
	while(atual){
		printf("%d ", atual->val);
		atual = atual->next;
	}
	printf("\n");
	
	return 0;
}