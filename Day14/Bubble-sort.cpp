//Problem - https://www.naukri.com/code360/problems/bubble-sort_980524



//this is optimized code 

#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
for (int i = 0; i < n-1; i++) {
        bool swapped = false;  // Optimization
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Stop if no swaps
    }
}


// #include <bits/stdc++.h> 
// void bubbleSort(vector<int>& arr, int n)
// {   
//     // Write your code here.
//     for(int i=0; i<n-1; i++){
//         for(int j =0; j<n-i-1; j++){
//             if (arr[j]> arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }
