#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* esq, struct ListNode* dir){
    struct ListNode *aux, *list;
    list = malloc(sizeof(struct ListNode));
    aux = list;

    while(esq && dir){
        if(esq->val <= dir->val){
            list->next = esq;
            esq = esq->next;
        } 
        else{
            list->next = dir;
            dir = dir->next;
        }
        list = list->next;
    }

    if(esq) list->next = esq;
    if(dir) list->next = dir;

    struct ListNode *result = aux->next;
    free(aux);
    return result;
}

struct ListNode* sortList(struct ListNode* head) {
    if(!head || !head->next) return head;//0 ou 1 elemento. 0 pois tem entrada lista vazia

    struct ListNode *slow = head, *fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    //quebrando a lista
    struct ListNode *temp = slow->next;//meio+1
    slow->next = NULL;

    struct ListNode *esq = sortList(head);
    struct ListNode *dir = sortList(temp);

    struct ListNode *result = merge(esq,dir);
    return result;
}
// int main(){
//     struct ListNode *n0 = malloc(sizeof(struct ListNode));
//     n0->val = 4;
//     struct ListNode *n1 = malloc(sizeof(struct ListNode));
//     n1->val = 2;
//     struct ListNode *n2 = malloc(sizeof(struct ListNode));
//     n2->val = 1;
//     struct ListNode *n3 = malloc(sizeof(struct ListNode));
//     n3->val = 3;

//     n0->next = n1;
//     n1->next = n2;
//     n2->next = n3;
//     sortList(n0);

//     return 0;
// }


