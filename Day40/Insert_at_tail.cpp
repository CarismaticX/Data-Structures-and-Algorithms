#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    public:
    Node(int data1, Node*next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

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

void print(Node*head){
    Node*temp = head;
    while(temp){
        cout<<temp->data <<"  ";
        temp = temp->next;
    }
}


//INSERTING AT HEAD

Node*InsertTail(Node*head, int val){
    if(head == NULL){
        return new Node(val);
    }

    Node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node*newNode = new Node(val);
    temp->next = newNode;

    return head;
}

int main() {

    vector<int> arr = {1,2,3,4,5,6,7};
    Node*head = convertArr2LL(arr);

    head = InsertTail(head, 5);
    print(head);

    return 0;
}