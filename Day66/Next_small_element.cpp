#include <bits/stdc++.h>
using namespace std;

// Function to find Next Smaller Element
vector<int> nextSmallerElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st; // will store indices

    for (int i = n - 1; i >= 0; i--) {
        int num = arr[i];

        // Pop all bigger or equal elements
        while (!st.empty() && arr[st.top()] >= num) {
            st.pop();
        }

        // If stack not empty → top is the NSE
        if (!st.empty()) res[i] = arr[st.top()];

        // Push current index
        st.push(i);
    }
    return res;
}

// ---------- MAIN FUNCTION ----------
int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> ans = nextSmallerElements(arr);

    cout << "Next Smaller Elements:\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
