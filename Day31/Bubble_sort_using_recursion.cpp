#include <iostream>
using namespace std;

void sortArray(int*arr, int size){
    //base case- If the Array is already sorted;

    if(size ==0 || size ==1){
        return ;
    }


    //1 case solve karo
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }


    //Recursive call
  return  sortArray(arr, size-1);
}

int main() {
    
    int arr[7] = {9,5,7,4,2,6,1,};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr,size);

//Printing the sorted array
    for(int i =0; i<size;i++){
        cout<<arr[i];
    }
    return 0;



}