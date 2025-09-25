class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (!st.empty() && arr[st.top()] > arr[i]) {
                cnt += left[st.top()];
                st.pop();
            }
            left[i] = cnt;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                cnt += right[st.top()];
                st.pop();
            }
            right[i] = cnt;
            st.push(i);
        }

        long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (long)arr[i] * left[i] * right[i]) % MOD;
        }
        return (int)res;
    }
};
