#include <iostream>
using namespace std;

void sortArray(int* arr,int start, int size){
 // Base case: if start reaches last element, stop
    if (start >= size - 1)
        return;

// Find the minimum element in unsorted part
    int minIndex = start;
    for(int i = start + 1; i< size; i++){
        if(arr[i]<arr[minIndex]){
            minIndex = i;
        }
    }
// Swap with first element of unsorted part
     swap(arr[start], arr[minIndex]);

//Recursive call
     sortArray(arr, start + 1, size);
}

int main() {
    
    int arr[7] = {9,5,7,4,2,6,1,};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr,0,size);

//Printing the sorted array
    for(int i =0; i<size;i++){
        cout<<arr[i];
    }
    return 0;



}