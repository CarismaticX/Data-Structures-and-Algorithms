#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "Printing array:" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Printing done." << endl;
}


int main(){

    int num[5] = {5,3 ,1};

    printArray(num, 5);

    return 0;
}