/*
📓 POINTERS IN C++ - My Personal Notes

What is a pointer?
- A pointer is a variable that stores the address of another variable.
- Instead of storing a value directly, it stores where that value lives in memory.
- Think of it like an address pointing to a house.

Syntax:
    int* p;   // pointer to int
    char* c;  // pointer to char
*/

#include <iostream>
using namespace std;

void greet() {
    cout << "Hello from greet() function!" << endl;
}

int main() {

    // 1. Basic pointer example
    int a = 10;
    int* p = &a;  // p stores the address of a

    cout << "Value of a: " << a << endl;
    cout << "Address of a (&a): " << &a << endl;
    cout << "Value in pointer p (address of a): " << p << endl;
    cout << "Value at *p: " << *p << endl << endl;

    // 2. Pointer to pointer
    int** q = &p;  // q stores the address of pointer p
    cout << "**q (double dereference): " << **q << endl << endl;

    // 3. Pointer arithmetic
    int arr[] = {10, 20, 30};
    int* ptr = arr;  // points to arr[0]

    cout << "First element: " << *ptr << endl;
    cout << "Second element: " << *(ptr + 1) << endl;
    cout << "Third element: " << *(ptr + 2) << endl << endl;
    // Note: ptr + 1 moves forward by sizeof(int) bytes

    // 4. Pointers & arrays
    cout << "Address of arr: " << arr << endl;
    cout << "First element (*arr): " << *arr << endl;
    cout << "Second element (*(arr + 1)): " << *(arr + 1) << endl << endl;

    // 5. Null pointer
    int* nullPtr = NULL;  // points to nothing
    cout << "nullPtr: " << nullPtr << endl << endl;

    // 6. Dynamic memory allocation
    int* dyn = new int(5);  // allocate memory and store 5
    cout << "Dynamic int value: " << *dyn << endl;
    delete dyn;  // free memory

    int* dynArr = new int[3]{1, 2, 3};  // dynamic array
    cout << "Dynamic array: " << dynArr[0] << ", " << dynArr[1] << ", " << dynArr[2] << endl;
    delete[] dynArr;
    cout << endl;

    // 7. Pointer to function
    void (*fp)() = greet;  // store address of greet()
    fp();  // call greet() through pointer
    cout << endl;

    // 8. Const with pointers
    int x = 100, y = 200;
    const int* ptrToConst = &x;  // can’t change value through this pointer
    ptrToConst = &y;  // but can point somewhere else

    int* const constPtr = &x;  // can’t change where it points
    *constPtr = 999;  // but can change the value

    cout << "ptrToConst points to: " << *ptrToConst << endl;
    cout << "constPtr points to: " << *constPtr << endl;

    return 0;
}

/*
Quick Recap:
1. &  gives address
2. *  dereferences (gets value at address)
3. Array name = pointer to first element
4. Pointer arithmetic moves by sizeof(data type)
5. Always delete what you ‘new’
6. Const with pointers can mean:
   - pointer to const data (can’t change value)
   - const pointer (can’t change address)
7. Pointers are used a lot in DSA for:
   - Passing large data without copying
   - Dynamic structures like linked lists, trees, graphs
   - Saving memory
*/
