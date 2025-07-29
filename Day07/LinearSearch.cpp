//Write a Program for Linear Search through an array 


#include <iostream>
using namespace std;


bool search(int arr[], int size, int key){

    for(int i=0; i<size; i++){
        if(arr[i] == key){
            return 1;
        }
    }
    return 0;

}

int main() {

    int num[12] ={1, -12, 14, 13, 78, 0, 9, 45, 23, 1123, 123};

    int key;
    cout<<"Enter the key you are Searching for "<<endl;
    cin>>key;

    bool found = search(num, 12, key);

    if(found){
        cout<<"Key is present"<<endl;
    }
    else{
        cout<<"Key is Absent"<<endl;
    }
    

    return 0;
}