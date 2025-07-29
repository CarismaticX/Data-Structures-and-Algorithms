//Problem Link - https://www.naukri.com/code360/problems/allocate-books_1090540



#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to allocate books such that
// maximum pages assigned to any student is <= mid
bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int studentCount = 1;   // Start with first student
    int pageSum = 0;        // Sum of pages assigned to current student

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            // Assign current book to current student
            pageSum += arr[i];
        } else {
            // Assign books to next student
            studentCount++;

            // If number of students exceeds m or single book pages > mid, return false
            if (studentCount > m || arr[i] > mid) {
                return false;
            }

            // Start counting pages for new student
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    // Edge case: if students more than books, allocation impossible
    if (m > n) return -1;

    // Initialize binary search boundaries
    // s should be max element (minimum possible max pages)
    int s = *max_element(arr.begin(), arr.end()); 

    // e is sum of all pages (maximum possible max pages)
    int e = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;

    // Binary search to find minimum max pages
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (isPossible(arr, n, m, mid)) {
            // mid is a valid max pages allocation, try to find smaller max
            ans = mid;
            e = mid - 1;
        } else {
            // mid too small, increase lower bound
            s = mid + 1;
        }
    }

    return ans;
}
