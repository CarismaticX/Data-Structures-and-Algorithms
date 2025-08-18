#include <iostream>
using namespace std;

int getPeak(int arr[], int s, int e, int n) {
    // base case
    if (s > e) return -1;

    int mid = s + (e - s) / 2;

    // check if mid is a peak
    if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&
        (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
        return mid;
    }

    // if left neighbor is greater, then peak must be on left side
    if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return getPeak(arr, s, mid - 1, n);
    }
    else {
        // else peak must be on right side
        return getPeak(arr, mid + 1, e, n);
    }
}

int main() {
    int arr[5] = {0, 4, 10, 5, 2};
    int n = 5;

    cout << "Peak element: " << getPeak(arr, 0, n - 1, n) << endl;

    return 0;
}
