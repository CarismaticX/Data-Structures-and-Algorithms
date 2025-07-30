int getPivot(vector<int>& arr, int size){
    int s = 0;
    int e = size - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    return s; // or return e;
}

int binarySearch(vector<int>& arr, int start, int end, int key){
    int s = start;
    int e = end;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums, nums.size());

    if (target >= nums[pivot] && target <= nums[nums.size() - 1]) {
        return binarySearch(nums, pivot, nums.size() - 1, target);
    } else {
        return binarySearch(nums, 0, pivot - 1, target);
    }
        
    }
};