#include <iostream>
using namespace std;

int Partition(int* arr, int s, int e) {
    int pivot = arr[s];
    int count = 0;

    // Count elements smaller than pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] < pivot) {
            count++;
        }
    }

    // Place pivot at right position
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    // Now arrange left and right side
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        if (arr[i] <= pivot) {
            i++;
        } 
        else if (arr[j] > pivot) {
            j--;
        } 
        else {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void QuickSort(int* arr, int s, int e) {
    if (s >= e) return;

    int p = Partition(arr, s, e);

    QuickSort(arr, s, p - 1);  // left part
    QuickSort(arr, p + 1, e);  // right part
}

int main() {
    int arr[9] = {9, 5, 7, 4, 2, 6, 1, 13, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, size - 1);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
