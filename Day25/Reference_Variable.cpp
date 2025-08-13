#include <iostream>
using namespace std;

int main() {
    // Example 1: basic reference
    int age = 20;
    int &refAge = age; // just another name for age

    cout << "age: " << age << endl;       // 20
    cout << "refAge: " << refAge << endl; // 20

    refAge = 25; // changing refAge changes age too
    cout << "after changing refAge, age: " << age << endl; // 25

    // Example 2: reference in function
    auto addFive = [](int &n) { n += 5; };
    addFive(age);
    cout << "after addFive, age: " << age << endl; // 30

    // Example 3: multiple references
    int &anotherRef = age; // anotherRef also refers to age
    anotherRef = 40;
    cout << "age after changing anotherRef: " << age << endl; // 40
    cout << "refAge also sees this: " << refAge << endl;      // 40

    // Example 4: reference vs pointer
    int *ptr = &age; // pointer to age
    *ptr = 50;       // change via pointer
    cout << "age after changing via pointer: " << age << endl; // 50

    // pointers can be null, references cannot
    int *nullPtr = nullptr; // ok
    // int &nullRef;        //  not allowed

    // Example 5: reference to const
    const int score = 100;
    const int &refScore = score; // cannot change through refScore
    cout << "score (const ref): " << refScore << endl; // 100

    return 0;
}
