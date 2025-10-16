#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool getPath(TreeNode* root, vector<int> &path, int target) {
    if (!root) return false;

    path.push_back(root->val);

    if (root->val == target) return true;

    if (getPath(root->left, path, target) || getPath(root->right, path, target))
        return true;

    // Backtrack if target not found in this path
    path.pop_back();
    return false;
}

vector<int> rootToNodePath(TreeNode* root, int target) {
    vector<int> path;
    if (root == NULL) return path;
    getPath(root, path, target);
    return path;
}

// MAIN
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int target = 5;
    vector<int> path = rootToNodePath(root, target);

    cout << "Path from root to node " << target << ": ";
    for (int x : path) cout << x << " ";
}
