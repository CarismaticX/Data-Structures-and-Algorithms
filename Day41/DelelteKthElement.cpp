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

Node*deleteHead(Node*head){
    if(head== NULL || head ->next == NULL){
        return NULL;
    }

    Node*prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;

}

Node*deleteTail(Node*head){
    if(head== NULL || head ->next == NULL){
        return NULL;
    }
    Node*temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }

    Node*newTail = temp->back;
    newTail->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node*removeKthElement(Node*head, int k){
    if(head == NULL ){
        return NULL;
    }

    int cnt = 0;
    Node*kNode = head;
    while(kNode != NULL){
        cnt++;
        if(cnt == k ) break;
        kNode = kNode->next;
    }

    Node*prev = kNode->back;
    Node*front = kNode->next;


    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    kNode->next = nullptr;
    kNode->back = nullptr;

    return head;

}

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    Node*head = convertArr2DLL(arr);
    head = removeKthElement(head,3);
    print(head);
    

    return 0;
}