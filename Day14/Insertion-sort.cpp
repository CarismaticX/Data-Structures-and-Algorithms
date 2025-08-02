//Problem - https://www.naukri.com/code360/problems/insertion-sort_3155179

#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
  for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}