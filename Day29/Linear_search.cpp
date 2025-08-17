#include <iostream>
using namespace std;
bool LinearSearch (int* arr, int size, int key){

    //base case
    if(size == 0){
        return 0;
    }


    if(arr[0] == key){
        return 1;
    }
   
    else{
    int remainingPart = LinearSearch(arr+1, size-1, key);
    }

    
}

int main() {

    int arr[5] = {2,3,5,7,9};

    int size  = 5;
    int key = 8;

   

    cout<<LinearSearch(arr, size, key)<<endl;

    

    return 0;
}