class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Sort the array
        sort(arr.begin(), arr.end());

        vector<int> v;
        int count = 1;

        // Count occurrences
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                v.push_back(count);
                count = 1;
            }
        }

        // Push count for the last group
        v.push_back(count);

        // Sort the frequency vector
        sort(v.begin(), v.end());

        // Check if any two frequencies are the same
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                return false;
            }
        }

        return true;
    }
};
