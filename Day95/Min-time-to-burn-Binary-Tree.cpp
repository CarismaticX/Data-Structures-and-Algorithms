#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to find minimum time to burn the tree from target node
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = mapParents(root, parent, target);

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;
            for (int i = 0; i < size; i++) {
                Node* curr = q.front(); q.pop();

                if (curr->left && !visited[curr->left]) {
                    burned = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right]) {
                    burned = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    burned = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            if (burned) time++;
        }
        return time;
    }

private:
    // Helper function to map each node to its parent
    Node* mapParents(Node* root, unordered_map<Node*, Node*>& parent, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            if (curr->data == target) targetNode = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
};

// Helper function to build a simple binary tree for demonstration
Node* buildTreeExample() {
    /*
             1
            / \
           2   3
          / \
         4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main() {
    // Build the binary tree
    Node* root = buildTreeExample();

    // Target node to start fire
    int target = 2;

    Solution obj;
    int timeToBurn = obj.minTime(root, target);

    cout << "Minimum time to burn the binary tree from node "
         << target << " = " << timeToBurn << " seconds." << endl;

    return 0;
}
