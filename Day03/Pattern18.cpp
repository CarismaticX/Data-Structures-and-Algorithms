// print pattern 
// ************
// *****  *****
// ****    ****
// ***      ***
// **        **
// *          *
// *          *
// **        **
// ***      ***
// ****    ****
// *****  *****
// ************



#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int spaces = 0;

    // Top half
    for (int i = 0; i < n; i++) {
        int stars = n - i;

        for (int j = 0; j < stars; j++) {
            cout << "*";
        }

        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        for (int j = 0; j < stars; j++) {
            cout << "*";
        }

        spaces += 2;
        cout << endl;
    }

    // Reset spaces for bottom half
    spaces -= 2;

    // Bottom half (should run for n iterations)
    for (int i = 0; i < n; i++) {
        int stars = i + 1;

        for (int j = 0; j < stars; j++) {
            cout << "*";
        }

        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        for (int j = 0; j < stars; j++) {
            cout << "*";
        }

        spaces -= 2;
        cout << endl;
    }

    return 0;
}
