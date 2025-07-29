//Given an array with only 0 and 1, sort them 


#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort(int arr[], int n){
    int i = 0, j = n - 1;

    while (i < j) {
        if (arr[i] == 0) {
            i++;
        }
        else if (arr[j] == 1) {
            j--;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

int main() {

    int arr[9] = {0,1,1,0,1,0,1,1,0};

    sort(arr, 9);

    printArray(arr, 9);
    

    return 0;
}