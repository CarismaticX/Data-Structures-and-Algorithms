//Print the sum of all the elemnts of an array;


#include <iostream>
using namespace std;
int sum(int arr[], int size){

    int sum =0;

    for(int i=0 ;i<size;i++){
        sum = sum + arr[i];
    }

    return sum;
}

int main() {
    int n;
    cin>>n;


    int num[1000]; 

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    cout<<"The sum of all the elements of array is :"<<sum(num, n)<<endl;

    return 0;
}