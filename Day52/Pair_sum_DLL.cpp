//Problem - https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1


// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
    
    private: 
    Node*findTail(Node*head){
        Node*tail = head;
        while(tail->next !=NULL){
            tail = tail->next;
        }
        return tail;
    }
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int,int>> ans;
        if(head == NULL) return ans;
        Node*left  = head;
        Node*right = findTail(head);
        
        while(left->data<right->data){
            if(left->data + right->data == target ){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
                
            }
            else if(left->data + right->data < target){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }
        return ans;
        // code here
        
    }
};