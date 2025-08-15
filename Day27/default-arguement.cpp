#include <iostream>
using namespace std;

// default arguments example
void greet(string name = "User", string msg = "Welcome!") {
    cout << "Hello " << name << ", " << msg << endl;
}

int main() {
    greet();                          // uses both defaults
    greet("Shekhar");                 // custom name, default msg
    greet("Shekhar", "Good Morning!");// custom name & msg
    return 0;
}
