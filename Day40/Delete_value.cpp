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


Node*removeVal(Node*head,int val){
    if(head == NULL) return head;

    if(head->data == val){
        Node*temp = head;
        head= head->next;
        free(temp);
        return head;
    }

   
    Node*temp = head;
    Node*prev = NULL;

    while(temp != NULL){
    
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;

        temp = temp->next;
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

int main() {

    vector<int> arr = {1,2,3,4,6,7,23,43,45,23,54,23,54,64};
    Node*head = convertArr2LL(arr);

    head = removeVal(head, 23);
    print(head);

    return 0;
}