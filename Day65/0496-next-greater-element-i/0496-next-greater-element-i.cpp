class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // Step 1: Compute NGE for nums2
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        // Step 2: Build result for nums1
        vector<int> ans;
        for (int x : nums1) {
            // Find index of x in nums2
            for (int j = 0; j < n; j++) {
                if (nums2[j] == x) {
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }

        return ans;
    }
};
