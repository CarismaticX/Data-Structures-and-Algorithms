#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Morris Inorder Traversal Function
vector<int> morrisInorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* current = root;

    while (current) {
        if (!current->left) {
            inorder.push_back(current->val);
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
                predecessor = predecessor->right;

            if (!predecessor->right) {
                predecessor->right = current;  // Create thread
                current = current->left;
            } else {
                predecessor->right = NULL;     // Revert thread
                inorder.push_back(current->val);
                current = current->right;
            }
        }
    }
    return inorder;
}

// Helper to print traversal
void printVector(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

// Main function to test
int main() {
    /* Example Tree:
              1
             / \
            2   3
           / \   \
          4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    vector<int> inorder = morrisInorderTraversal(root);
    
    cout << "Morris Inorder Traversal: ";
    printVector(inorder);

    return 0;
}
