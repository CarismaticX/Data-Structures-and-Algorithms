//Problem - https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

#include <iostream>
using namespace std;

int First(int arr[], int size, int key) {
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

int Last(int arr[], int size, int key) {
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

int main() {
    int arr[10] = {1, 2, 3, 3, 3, 3, 4, 3, 10, 76};

    
    cout << "Index of first occurence is  " << First(arr, 10 , 3)<<endl;
    
    cout << "Index of Last occurence is  " << Last(arr, 10 , 3)<<endl;

    return 0;
}
