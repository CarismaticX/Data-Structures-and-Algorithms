class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // slow pointer: points to the last unique element

        for (int j = 1; j < nums.size(); j++) { // fast pointer
            if (nums[j] != nums[i]) { // found a new unique element
                i++;              // move slow pointer
                nums[i] = nums[j]; // update next unique position
            }
        }

        return i + 1; // length of array with unique elements
    }
    
};