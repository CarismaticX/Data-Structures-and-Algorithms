#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print(Node*head){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
    
}


Node*convertArr2DLL(vector<int>&arr){
    Node*head = new Node(arr[0]);
    Node*prev = head;
    for(int i=1; i<arr.size();i++){
        Node*temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;

}

Node*InsertBeforeHead(Node*head, int val){
    Node*newhead = new Node(val,head,nullptr);
    head->back = nullptr;
    return newhead;
}

Node*InsertBeforeTail(Node*head, int val){
    if(head->next == NULL){
        return InsertBeforeHead(head, val);
    }
    Node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node*prev = tail->back;
    Node*newNode = new Node(val,tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}



int main() {
    vector<int> arr = {1,2,3,4,5,6};
    Node*head = convertArr2DLL(arr);
    head = InsertBeforeTail(head, 2);
    print(head);
    

    return 0;
}