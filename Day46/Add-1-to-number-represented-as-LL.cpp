//Problem- https://www.naukri.com/code360/problems/add-one-to-a-number-represented-as-linked-list_920557

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

int addHelper(Node* temp) {
    if (temp == NULL) return 1; // carry = 1 (add 1 at end)

    int carry = addHelper(temp->next);
    temp->data += carry;

    if (temp->data < 10) return 0; // no more carry
    temp->data = 0;
    return 1; // carry forward
}

// Main function
Node* addOne(Node* head) {
    int carry = addHelper(head);

    if (carry) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}