// Problem - https://www.naukri.com/code360/problems/selection-sort_981162


#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i =0; i<n-1; i++){
        int midIndex =i;
        for(int j =i+1; j<n; j++){
            if(arr[midIndex] > arr[j]){
                midIndex =j;
            }
            
        }
        swap(arr [midIndex],  arr[i]);
    }
}