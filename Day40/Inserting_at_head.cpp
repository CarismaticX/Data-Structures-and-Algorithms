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

Node*InsertHead(Node*head, int val){
    Node*temp = new Node(val, head);
    return temp;
}

int main() {

    vector<int> arr = {1,2,3,4,6,7,23,43,45,23,54,23,54,64};
    Node*head = convertArr2LL(arr);

    head = InsertHead(head, 5);
    print(head);

    return 0;
}