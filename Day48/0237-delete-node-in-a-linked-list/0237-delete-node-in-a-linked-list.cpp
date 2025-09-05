/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


        class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy next node’s value
        node->val = node->next->val;
        // Store pointer to next node
        ListNode* temp = node->next;
        // Skip the next node
        node->next = node->next->next;
        // Delete next node
        delete temp;
    }
};

        
    
