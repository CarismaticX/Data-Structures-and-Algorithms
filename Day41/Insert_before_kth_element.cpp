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

Node*InsertBeforeKthElement(Node*head, int k, int val ){
    if(k==1){
        return InsertBeforeHead(head, val);
    }

    Node*temp = head;
    int cnt =0;
    while(temp != NULL ){
        cnt++;
        if(cnt == k )break;
        temp = temp->next;
    }


    Node*prev = temp->back;
    Node*newNode = new Node(val,temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}



int main() {
    vector<int> arr = {1,2,3,4,5,6};
    Node*head = convertArr2DLL(arr);
    head = InsertBeforeKthElement(head, 2,56);
    print(head);
    

    return 0;
}