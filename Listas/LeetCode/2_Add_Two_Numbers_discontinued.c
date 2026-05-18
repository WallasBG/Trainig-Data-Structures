#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
	 int val;
	 struct ListNode *next;
 };

struct ListNode *create_node(int val){
	struct ListNode *novo_no = (struct ListNode *)malloc(sizeof(struct ListNode));
	if(!novo_no) return NULL;

	novo_no->next = NULL;
	novo_no->val = val;

	return novo_no;
}

struct ListNode *add(struct ListNode *head, int val){// add at begin and return head
	struct ListNode *novo_no = create_node(val);
	novo_no->next = head;
	return novo_no;	
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *vetor[] = {l1, l2};

	long long soma = 0;
	int maior=0, n;
	long long power;

	for(int i=0; i<2; i++){
		struct ListNode *atual = vetor[i]; n = 0;
		while(atual){
			power = pow(10,n);
			soma += atual->val * power;
			printf("soma: %lld\n", soma);
			atual = atual->next; n++;
		}
		if(n>maior) maior = n;
	}
	n=maior;
	printf("n = %d \n", n);

	int dig;
	struct ListNode *head = NULL;

	while(n>=0){
		 power = pow(10,n); 

		dig = soma / power;
		if(n == maior && !dig){
			n--;
			continue;
		}
		head = add(head,dig);
		soma -= dig*power;
		n--;
	}
	return head;
}

//--------------------------------------------------------

void my_print(struct ListNode *head){
	struct ListNode *atual = head;

	while(atual){
		printf("%d ", atual->val);
		atual = atual->next;
	}
	printf("\n");
}

int main(){
	struct ListNode *l1 = add(NULL,1);
	l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 1);
	my_print(l1);

	struct ListNode *l2 = add(NULL,4);
	l2 = add(l2, 6); l2 = add(l2,5);
	// l2 = add(l2,9);
	my_print(l2);

	struct ListNode *h = addTwoNumbers(l1,l2);
	my_print(h);

	return 0;
}