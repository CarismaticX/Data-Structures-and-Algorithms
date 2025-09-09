//Problem Link- https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1


// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;

        while (temp != NULL) {
            if (temp->data == x) {
                // if deleting head
                if (temp == *head_ref) {
                    *head_ref = temp->next;
                }

                Node* prevNode = temp->prev;
                Node* nextNode = temp->next;

                if (prevNode) prevNode->next = nextNode;
                if (nextNode) nextNode->prev = prevNode;

                Node* toDelete = temp;
                temp = nextNode;   // move forward
                delete toDelete;
            } 
            else {
                temp = temp->next;
            }
        }
    }
};
