//Problem - https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
private:
    Node* merge(Node* first, Node* second) {
        Node* t1 = first;
        Node* t2 = second;
        Node* dummyNode = new Node(-1);

        Node* temp = dummyNode;

        while (t1 != NULL && t2 != NULL) {
            if (t1->data < t2->data) {
                temp->bottom = t1;
                temp = t1;
                t1 = t1->bottom;
            }
            else {
                temp->bottom = t2;
                temp = t2;
                t2 = t2->bottom;
            }
        }

        if (t1) temp->bottom = t1;
        else temp->bottom = t2;

        return dummyNode->bottom;
    }

public:
    Node* flatten(Node* root) {
        if (root == NULL || root->next == NULL) {
            return root;   // fixed from head → root
        }

        Node* mergeHead = flatten(root->next);
        root = merge(root, mergeHead);
        return root;
    }
};
