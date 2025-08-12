#include <iostream>
using namespace std;

// Function that takes a pointer to an integer and increments the value it points to
void increment(int *ptr) {
    // Dereference the pointer to access the value and increment it
    (*ptr)++;
}

// Function that swaps two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;  // store the value pointed by a in temp
    *a = *b;        // assign the value pointed by b to the location pointed by a
    *b = temp;      // assign temp to the location pointed by b
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Before increment: x = " << x << endl;
    increment(&x); // pass the address of x to increment function
    cout << "After increment: x = " << x << endl;

    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(&x, &y); // pass addresses of x and y to swap function
    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
