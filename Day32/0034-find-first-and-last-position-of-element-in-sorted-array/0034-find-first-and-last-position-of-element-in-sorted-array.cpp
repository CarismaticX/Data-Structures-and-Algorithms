class Solution {
public:
    int findFirst(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            int leftResult = findFirst(nums, left, mid - 1, target);
            return (leftResult != -1) ? leftResult : mid;
        } else if (nums[mid] < target) {
            return findFirst(nums, mid + 1, right, target);
        } else {
            return findFirst(nums, left, mid - 1, target);
        }
    }
    
    int findLast(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            int rightResult = findLast(nums, mid + 1, right, target);
            return (rightResult != -1) ? rightResult : mid;
        } else if (nums[mid] < target) {
            return findLast(nums, mid + 1, right, target);
        } else {
            return findLast(nums, left, mid - 1, target);
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, 0, nums.size() - 1, target), findLast(nums, 0, nums.size() - 1, target)};
    }
};
