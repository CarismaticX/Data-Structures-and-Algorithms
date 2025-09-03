#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// Function to check if linked list is palindrome
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true;

    // Step 1: Find middle using slow & fast pointer
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* newHead = reverseLinkedList(slow->next);

    // Step 3: Compare both halves
    Node* first = head;
    Node* second = newHead;
    while (second != NULL) {
        if (first->data != second->data) {
            reverseLinkedList(newHead); // restore
            return false;
        }
        first = first->next;
        second = second->next;
    }

    // Step 4: Restore list & return true
    reverseLinkedList(newHead);
    return true;
}

// Helper function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << (isPalindrome(head) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
