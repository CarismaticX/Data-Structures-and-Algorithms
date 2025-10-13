#include <bits/stdc++.h>
using namespace std;

// ----------------- Tree Node Definition -----------------
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ----------------- Build Tree from Level Order -----------------
// Input: Level order array where -1 represents NULL
Node* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// ----------------- Bottom View Function -----------------
vector<int> bottomView(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    map<int, int> mp; // hd -> node value
    queue<pair<Node*, int>> q; // node, hd
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Overwrite to get bottom-most node at each horizontal distance
        mp[hd] = node->data;

        if (node->left)  q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto &it : mp)
        ans.push_back(it.second);

    return ans;
}

// ----------------- Main Function -----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of nodes in level order (use -1 for NULL): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter level order traversal: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);
    vector<int> result = bottomView(root);

    cout << "Bottom View: ";
    for (int val : result) cout << val << " ";
    cout << "\n";

    return 0;
}
