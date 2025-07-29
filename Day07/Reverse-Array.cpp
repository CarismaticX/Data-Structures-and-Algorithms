//write a Program to reverse an array.


#include <iostream>
using namespace std;

void reverseArray(int arr[], int n){

    int start =0 ;
    int end = n-1;

    while(start<end){

        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int size){

    for(int i=0; i<size;i++){
        cout<<arr[i] << " ";
    }
}

int main() {

    int first[5] ={1,2,3,4,7};
    int second[9] ={12,13,56,12,4,5,6,7,32};

    reverseArray(first,5);
    reverseArray(second,9);

    printArray(first,5);
    cout<<endl;
    printArray(second,9);

    return 0;
}