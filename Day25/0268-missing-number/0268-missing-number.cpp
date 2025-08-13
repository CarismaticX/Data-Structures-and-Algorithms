class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int sum1 = 0;
        int sum2 = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            sum1 += nums[i];
        }

        for(int j = 0; j <= n; j++){  // sum of 0 to n
            sum2 += j;
        }

        ans = sum2 - sum1;

        return ans;
    }
};
