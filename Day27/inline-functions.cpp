#include <iostream>
using namespace std;

// inline function to calculate square
inline int square(int x) {
    return x * x;
}

int main() {
    cout << "Square of 4: " << square(4) << endl;
    cout << "Square of 7: " << square(7) << endl;
    return 0;
}
