//Problem - https://www.geeksforgeeks.org/problems/find-length-of-loop/1


/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
    private: 
    int findLength(Node*slow, Node*fast){
        int cnt = 1;
        fast = fast->next;
        
        while(fast!= slow){
            cnt++;
            fast = fast->next;
        }
        return cnt;
    }
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node*slow = head;
        Node*fast= head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                return findLength(slow, fast);
            }
        }
        return 0;
    }
};