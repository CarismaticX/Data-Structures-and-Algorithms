#include <iostream>
using namespace std;

int getsum (int* arr, int size){

    //base case
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }

    int remainingPart = getsum(arr+1, size-1);
    int sum = arr[0] + remainingPart;

    return sum;
}

int main() {

    int arr[5] = {2,3,5,7,9};

    int size  = 5;

    int sum = getsum(arr, size);

    cout<<sum<<endl;

    

    return 0;
}