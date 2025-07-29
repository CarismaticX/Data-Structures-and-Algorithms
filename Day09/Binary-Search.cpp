//Introductory Program to binary search


#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;  // safer way to avoid overflow

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;  // element not found
}

int main() {
    int even[8] = {2, 6, 8, 12, 43, 56, 57, 90};
    int odd[5] = {1, 2, 5, 7, 54};

    int index = binarySearch(even, 8, 56);
    cout << "Index of 56 is " << index << endl;

    return 0;
}
