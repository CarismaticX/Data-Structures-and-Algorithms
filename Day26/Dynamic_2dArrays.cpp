//Examples of how dynamic memory is allocated to a 2d array

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    // Step 1: Allocate memory for row pointers
    int** arr = new int*[rows];

    // Step 2: Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Step 3: Input values
    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];

    // Step 4: Output values
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // Step 5: Free memory
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}
