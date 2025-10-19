#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

// Function to reorder tree to satisfy Children Sum Property
void reorder(Node* root) {
    if (!root) return;

    int child = 0;
    if (root->left) child += root->left->val;
    if (root->right) child += root->right->val;

    if (child >= root->val) root->val = child;
    else {
        if (root->left) root->left->val = root->val;
        if (root->right) root->right->val = root->val;
    }

    reorder(root->left);
    reorder(root->right);

    int total = 0;
    if (root->left) total += root->left->val;
    if (root->right) total += root->right->val;

    if (root->left || root->right)
        root->val = total;
}

// Helper: print inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
         50
        /  \
       7    2
      / \  / \
     3  5 1  30
    */

    Node* root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    cout << "Inorder before modification: ";
    inorder(root);
    cout << endl;

    reorder(root);

    cout << "Inorder after modification:  ";
    inorder(root);
    cout << endl;

    return 0;
}
