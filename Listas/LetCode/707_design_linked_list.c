#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------



typedef struct node{
	struct node *next;
	struct node *prev;
	int val;
}node;

typedef struct {
	node *head;
	node *tail;
	int size;    
} MyLinkedList;

node *node_create(int value){
	node *novo_no = (node *)malloc(sizeof(node));
	if(!novo_no) return NULL;

	novo_no->val = value;
	novo_no->next = NULL; novo_no->prev = NULL;

	return novo_no; 
}

MyLinkedList* myLinkedListCreate() {
	MyLinkedList *pt_lista = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	if(!pt_lista) return NULL;

	pt_lista->head = NULL; pt_lista->tail = NULL;
	pt_lista->size = 0;

	return pt_lista;    
}

int myLinkedListGet(MyLinkedList* obj, int index) {//devolve valor da posi
	if(index>=0 && index<obj->size){
		int meio = obj->size/2, idx;
		node *atual = NULL;

		if(index < meio){
			idx = 0; atual = obj->head;
			while(idx < index){
				atual = atual->next;
				idx ++;
			}
		}
		else{//index >= meio
			idx = obj->size-1; atual = obj->tail;
			while(idx > index){
				atual = atual->prev;
				idx --;
			}
		}
		return atual->val;
	}
	return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {//add inicio
	node *novo_no = node_create(val);

	if(!obj->head){//empty
		obj->tail = novo_no;
	}
	else{
		novo_no->next = obj->head;
		obj->head->prev = novo_no;
	}
	obj->head = novo_no; 
	obj->size++;    
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {//add final
	if(!obj->head){//lista vazia
		myLinkedListAddAtHead(obj, val);
	}
	else{
		node *novo_no = node_create(val);
		novo_no->prev = obj->tail;
		obj->tail->next = novo_no;
		obj->tail = novo_no;
		obj->size++;
	}    
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	if(index>=0 && index<=obj->size){
		if(!index){
			myLinkedListAddAtHead(obj,val);
		}
		else if(index == obj->size){
			myLinkedListAddAtTail(obj,val);
		}
		else{
			int idx=0; node *atual = obj->head;
			while(idx<index){
				idx++;
				atual = atual->next;
			}
			node *anterior = atual->prev;
			node *novo_no = node_create(val);
			novo_no->prev = anterior; novo_no->next = atual;
			anterior->next = novo_no; atual->prev = novo_no;

			obj->size++;
		}
	}
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	if(index >= 0 && index < obj->size){//index valid, no empty list
		node *atual = NULL;

		if(!index){//start or single elem cases
			atual = obj->head;
			if(!atual->next){//unico elem 
				obj->tail = atual->next;
			}
			else{
				node *prox = atual->next;
				prox->prev = atual->prev;
			}
			obj->head = atual->next;
		}

		else if(index == obj->size -1){//end
			node *anterior = obj->tail->prev;
			atual = obj->tail;

			anterior->next = atual->next;//NULL
			obj->tail = anterior;
		}
		else{//middle
			int meio = obj->size/2, idx;

			//mais proximo da head
			if(index < meio){
				atual = obj->head;
				idx = 0;

				while(idx < index){	
					atual = atual->next;
					idx++;
				}
			}
			//mais proximo da tail
			else{//index >= meio
				atual = obj->tail;
				idx = obj->size -1;

				while(idx > index){
					atual = atual->prev;
					idx--;
				}
			}

			node *anterior = atual->prev, *proximo = atual->next;
			anterior->next = proximo;
			proximo->prev = anterior;
		}
		free(atual);
		obj->size--;
	}   
}

void myLinkedListFree(MyLinkedList* obj) {
	node *atual = obj->head, *proximo = NULL;

	while(atual){
		proximo = atual->next;
		free(atual);
		atual = proximo;
	}
	free(obj);    
}




//----------------------------------------------------------------------
void print_front(MyLinkedList *obj){
	node *atual = obj->head;

	while(atual){
		printf("%d ", atual->val);
		atual = atual->next;
	}
	printf("\n");
}

void print_back(MyLinkedList *obj){
	node *atual = obj->tail;

	while(atual){
		printf("%d ", atual->val);
		atual = atual->prev;
	}
	printf("\n");
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

int main(){
	MyLinkedList *my_list = myLinkedListCreate();

	myLinkedListAddAtTail(my_list, 0);
	myLinkedListAddAtTail(my_list, 1);
	myLinkedListAddAtTail(my_list, 2);
	myLinkedListAddAtTail(my_list, 3);
	myLinkedListAddAtTail(my_list, 4);

	print_front(my_list);
	print_back(my_list);

	printf("%d\n",myLinkedListGet(my_list, -1));
	printf("%d\n",myLinkedListGet(my_list, 0));
	printf("%d\n",myLinkedListGet(my_list, 1));
	printf("%d\n",myLinkedListGet(my_list, 2));
	printf("%d\n",myLinkedListGet(my_list, 3));
	printf("%d\n",myLinkedListGet(my_list, 4));
	printf("%d\n",myLinkedListGet(my_list, 5));
	printf("%d\n",myLinkedListGet(my_list, 999));

	myLinkedListDeleteAtIndex(my_list,0);
	print_front(my_list);
	print_back(my_list);


	myLinkedListDeleteAtIndex(my_list, my_list->size -1);
	print_front(my_list);
	print_back(my_list);

	myLinkedListDeleteAtIndex(my_list, 1);
	print_front(my_list);
	print_back(my_list);

	myLinkedListDeleteAtIndex(my_list, 0); myLinkedListDeleteAtIndex(my_list, 0);
	print_front(my_list);
	print_back(my_list);

	myLinkedListAddAtHead(my_list, 3);
	myLinkedListAddAtHead(my_list, 2);
	myLinkedListAddAtHead(my_list, 1);
	myLinkedListDeleteAtIndex(my_list, 1);
	myLinkedListDeleteAtIndex(my_list, 0);
	print_front(my_list);
	print_back(my_list);

	printf("%d\n", my_list->size);

	myLinkedListAddAtIndex(my_list,0,1111);
	print_front(my_list);
	print_back(my_list);
	myLinkedListAddAtIndex(my_list,my_list->size,999);
	print_front(my_list);
	print_back(my_list);
	myLinkedListAddAtIndex(my_list,1,767);
	print_front(my_list);
	print_back(my_list);
	printf("%d\n", my_list->size);

	myLinkedListFree(my_list);




	return 0;
}