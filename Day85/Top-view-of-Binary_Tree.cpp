#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* -------- Solution Class -------- */
class Solution {
public:
    vector<int> topView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        // map<vertical index, node value>
        map<int, int> topNode;
        queue<pair<TreeNode*, int>> q; // node + vertical level
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second;

            // store the first node at each vertical line
            if (topNode.find(line) == topNode.end())
                topNode[line] = node->val;

            // push children with updated horizontal distance
            if (node->left)
                q.push({node->left, line - 1});
            if (node->right)
                q.push({node->right, line + 1});
        }

        // collect nodes in sorted order of vertical lines
        for (auto &it : topNode)
            ans.push_back(it.second);

        return ans;
    }
};

/* -------- Helper Function to Build Tree -------- */
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

/* -------- Main Function -------- */
int main() {
    /*
             1
            / \
           2   3
          / \   \
         4   5   6
                  \
                   7
    */

    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->right->right->right = newNode(7);

    Solution sol;
    vector<int> ans = sol.topView(root);

    cout << "Top View of the Binary Tree: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
