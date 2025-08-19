#include <iostream>
using namespace std;


void merge(int *arr, int s, int e){

    int mid = (s+e)/2 , len1 = mid-s+1, len2 = e - mid;

    int*first = new int [len1];
    int*second = new int [len2];

    //copy values 

    int mainArrayIndex = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid +1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }


    //merge 2 sorted Arrays 

    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = s;

    while(index1< len1 && index2< len2){
        if(first[index1] <second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }


    while(index1<len1){
        arr[mainArrayIndex++]= first[index1++];
    }

     while(index2<len2){
        arr[mainArrayIndex++]= second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int*arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    int mid = (s+e)/2;

    //left part soft krna hai
    mergeSort(arr,s,mid);

    //right part sort karna hai
    mergeSort(arr, mid+1, e);

   //merger
   merge(arr,s,e);
}

int main() {
    
    int arr[7] = {9,5,7,4,2,6,1,};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr,0,6);

//Printing the sorted array
    for(int i =0; i<size;i++){
        cout<<arr[i];
    }
    return 0;



}