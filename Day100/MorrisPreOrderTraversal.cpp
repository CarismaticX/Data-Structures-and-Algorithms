#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Morris Preorder Traversal Function
vector<int> morrisPreorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* current = root;
    
    while (current) {
        if (!current->left) {
            preorder.push_back(current->val);
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
                predecessor = predecessor->right;
            
            if (!predecessor->right) {
                predecessor->right = current;
                preorder.push_back(current->val); // Visit before going left
                current = current->left;
            } else {
                predecessor->right = NULL; // Revert the thread
                current = current->right;
            }
        }
    }
    return preorder;
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
    
    vector<int> preorder = morrisPreorderTraversal(root);
    
    cout << "Morris Preorder Traversal: ";
    