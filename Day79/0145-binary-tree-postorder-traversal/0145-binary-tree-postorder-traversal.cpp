/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = NULL;

        while (curr != NULL || !st.empty()) {
            // Step 1: Go to leftmost node
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } 
            else {
                TreeNode* peekNode = st.top();
                // Step 2: If right child exists and not visited, go right
                if (peekNode->right != NULL && lastVisited != peekNode->right) {
                    curr = peekNode->right;
                } 
                // Step 3: If no right child, visit node
                else {
                    postorder.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }

        return postorder;
    }
};
