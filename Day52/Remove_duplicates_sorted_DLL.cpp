//Problem - https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node*temp = head;
        while(temp!= NULL && temp->next !=NULL){
            Node*nextNode = temp->next;
            
            while(nextNode!=NULL && nextNode->data == temp->data){
                Node*duplicate = nextNode;
                nextNode = nextNode->next;
                free(duplicate);
            }
            
            temp->next = nextNode;
            if(nextNode != NULL ){
                nextNode->prev = temp;
            }
            temp = temp->next;
        }
        
        return head;
    }
};