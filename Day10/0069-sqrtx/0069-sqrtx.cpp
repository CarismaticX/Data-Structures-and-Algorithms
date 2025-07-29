class Solution {
public:
    int binarySearch(int n) {
        int s = 0;
        int e = n;
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long square = (long long)mid * mid;  // use long long to avoid overflow

            if (square == n) {
                return mid;
            } else if (square > n) {
                e = mid - 1;
            } else {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }

    int mySqrt(int x) {
        return binarySearch(x);
    }
};
