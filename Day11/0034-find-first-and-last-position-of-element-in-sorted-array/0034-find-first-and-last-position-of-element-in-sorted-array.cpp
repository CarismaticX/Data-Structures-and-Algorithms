int First(vector<int>& arr, int size, int key) {
    int s = 0;
    int e = size - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;  

        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;  
}

int Last(vector<int>& arr, int size, int key) {
    int s = 0;
    int e = size - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;  

        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;  
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        pair<int, int> p;
        p.first = First(nums, nums.size(), target);
        p.second = Last(nums, nums.size(), target);
        
        return {p.first, p.second};
    }
};
