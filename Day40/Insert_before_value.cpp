#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

// INSERTING AT K
Node* InsertBeforeValue(Node* head, int el, int val) {
    if (head == NULL) {
        if (val == 1)
            return new Node(el);
    }


    if(head->data == val){
        return new Node(el,head);
    }

    
    Node*temp = head;
    while(temp->next!= NULL){
        if(temp->next->data == val){
            Node*x = new Node (el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;

    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* head = convertArr2LL(arr);

    head = InsertBeforeValue(head, 13, 6);
    print(head);

    return 0;
}
