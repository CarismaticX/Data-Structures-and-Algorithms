class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        // Contribution as maximum
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long cnt = (long long)(mid - left) * (right - mid);
                ans += (long long)nums[mid] * cnt;
            }
            st.push(i);
        }

        // Contribution as minimum
        while (!st.empty()) st.pop();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long cnt = (long long)(mid - left) * (right - mid);
                ans -= (long long)nums[mid] * cnt;
            }
            st.push(i);
        }

        return ans;
    }
};
