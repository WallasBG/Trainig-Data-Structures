/* well, in the last implementation, i get trouble to store numbers with over 20 something digits,
imagine this for numbers with up to 101 digits.

so, now the solution is try strings,
well, we'll do make a full adder,  and before this, cath each number of list, turn to char and make a string vector.
so, let code...
 fiz desse jeito acima, pegando numero por numero e transformando em string, depois invertir
peguei um numero de cada vez e fiz um somador completo como em Cicuitos Logicos, com o resultado pronto,
coloquei em outra string, depois transformei em num, e fiz um add e pronto
resultou em tempo de 5ms, nao salvei o cod, vou ver como ir codando em salvar no git
um bom problema a solucao abaixo é a melhor */

//tem outro jeito melhor ainda, somar de tras pra frente, abaixo

#include <stdio.h>
#include <stdlib.h>

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

// struct ListNode *append(struct ListNode *head, int val, struct ListNode *end){
// 	struct ListNode *novo_no = create_node(val);
// 	if(!head){
// 		novo_no->next = head;
// 	}
// 	else{
// 		end->next = novo_no;
// 	}
// 	return novo_no;
// }


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode *sinal = create_node(-1);

	//  FULL ADDER
 
	int carry = 0;
	struct ListNode *atual = sinal;

	while(l1 || l2 || carry){
		int x = (l1)? l1->val : 0; 
		int y = (l2)? l2->val : 0;

		int soma = (x + y + carry) % 10;
		atual->next = create_node(soma);
		atual = atual->next;
		carry = (x + y + carry) / 10;

		if(l1) l1 = l1->next; 
		if(l2) l2 = l2->next;
	}

	return sinal->next;
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
	// int num = 8;
	// printf("0 in ascii = %d\n", '0');//48

	// char num_str = 48 + 8;
	// printf("%c\n", num_str);

	// char palavra[5] = {48, 49, 50, 51, 52};
	// printf("%s\n",palavra);


	struct ListNode *l1 = add(NULL,3);
	l1 = add(l1, 4); l1 = add(l1, 2); //l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	// l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	// l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	// l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	// l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0);
	// l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 0); l1 = add(l1, 1);
	my_print(l1);

	struct ListNode *l2 = add(NULL,4);
	l2 = add(l2, 6); l2 = add(l2, 5);
	// l2 = add(l2,9);
	my_print(l2);

	//addTwoNumbers(l1,l2);

	struct ListNode *h = addTwoNumbers(l1,l2);
	my_print(h);

	return 0;
}














/////fazer soma comum e colocar numa string e spois inverter, e depois imprimir