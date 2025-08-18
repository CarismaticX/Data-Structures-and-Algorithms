#include <iostream>
using namespace std;


int getPivot(int*arr, int s, int e , int size){

    if(s==e){
        return s;
    }

    int mid = s+(e-s)/2;

    if(arr[mid]>=arr[0]){
        return getPivot(arr, mid+1, e, size);
    }
    else{
        return getPivot(arr,s,mid,size);
    }
}

int main() {

    int arr[6] ={4,5,6,1,2,3};

    cout<<"The Pivot element in the arrays is "<<getPivot(arr, 0, 5, 6);
    

    return 0;
}