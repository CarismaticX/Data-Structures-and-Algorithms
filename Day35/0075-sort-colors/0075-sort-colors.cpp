class Solution {

    private:
    void sort012(vector<int>& nums, int n) {
    int i = 0, j = 0, k = n - 1;

    while (j <= k) {
        if (nums[j] == 0) {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else if (nums[j] == 2) {
            swap(nums[j], nums[k]);
            k--;
            // Don't increment j here
        }
        else { // arr[j] == 1
            j++;
        }
    }
}

public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        sort012(nums, n);
        
    }
};