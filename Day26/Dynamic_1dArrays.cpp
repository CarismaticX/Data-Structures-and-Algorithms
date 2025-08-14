#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // Allocate memory dynamically in heap
    int* arr = new int[n];  

    // Take input
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display output
    cout << "Array elements are: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free memory and avoid dangling pointer
    delete[] arr;  
    arr = nullptr; 

    return 0;
}
