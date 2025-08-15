#include <iostream>
using namespace std;

// Function to calculate 2^n using recursion
int powerOfTwo(int n) {
    // Base case: 2^0 = 1
    if (n == 0) return 1;

    // Recursive case: 2^n = 2 * 2^(n-1)
    return 2 * powerOfTwo(n - 1);
}

int main() {
    int n;
    cout << "Enter exponent n: ";
    cin >> n;

    cout << "2^" << n << " = " << powerOfTwo(n) << endl;

    return 0;
}
