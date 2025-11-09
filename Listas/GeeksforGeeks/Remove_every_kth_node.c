/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        int i = 1;
        Node *atual = head;
        Node *anterior = NULL;

        while(atual != NULL){
            if(i == k){//hora de remover

                if(anterior == NULL){//remover o primeiro
                    head = atual->next;
                }
                else{//remover no meio ou no fim
                    anterior->next = atual->next;
                }

                //tratando as atualizacoes, pos remocao
                free(atual);
                if(anterior == NULL){//removi no comeco
                    atual = head;
                }
                else{
                    atual = anterior->next;
                }
                i = 1;
            }
            else{
                i ++;
                anterior = atual;
                atual = atual->next;
            }
        }
        
        return head;
        
    }
};