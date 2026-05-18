#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *ant = NULL, *atual = head, *prox = NULL; 

	if(atual && atual->next) prox = head->next;
	else return head;

	while(1){
		atual->next = ant;
		ant = atual;
		atual = prox;
		prox = prox->next;
		if(!prox){
			atual->next = ant;
			return atual;
		}
	}  
}
/*   or better

struct ListNode *ant = NULL, *atual = head, *prox = NULL;

while(atual){
	prox = atual->next;
	atual->next = ant;
	ant = atual;
	atual = prox;	
}

return ant;

*/

int main(){


	return 0;
}