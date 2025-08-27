#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    public:
    Node(int data1,Node*next1 ){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

//ARRAY TO LINKED LIST
Node*convertArr2LL(vector<int>&arr){
    Node*head = new Node(arr[0]);
    Node*mover = head;
    for(int i=1;i<arr.size();i++){

        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
//REMOVING THE TAIL 
Node*removeTail(Node*head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node*temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

//Print 
void print(Node*head){
    Node*temp = head;
    while(temp){
        cout<<temp->data;
        temp = temp->next;
    }
}



int main() {

    vector<int>arr = {1,2,34,56,77,88,99};
    Node*head = convertArr2LL(arr);
    head = removeTail(head);
    print(head);
    

    return 0;
}