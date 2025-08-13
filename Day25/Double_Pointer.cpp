#include <iostream>
using namespace std;

void singlePointer(int *p) {
    *p = 50; // can change the value
    int y = 100;
    p = &y;  // does NOT change original pointer
}

void doublePointer(int **pp) {
    int static y = 200;
    *pp = &y; // changes the original pointer
}

int main() {
    int x = 10;
    int *p = &x;

    cout << "Value: " << *p << "\n";
    singlePointer(p);
    cout << "After singlePointer - Value: " << *p << "\n"; // value changed, pointer same

    doublePointer(&p);
    cout << "After doublePointer - Value: " << *p << "\n"; // pointer changed
}
