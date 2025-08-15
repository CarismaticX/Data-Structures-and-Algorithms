#include <iostream>
using namespace std;

// defining a constant using macro
#define PI 3.14159

// macro for finding square
#define SQUARE(x) ((x) * (x))

int main() {
    cout << "PI value: " << PI << endl;
    cout << "Square of 5: " << SQUARE(5) << endl;
    return 0;
}
