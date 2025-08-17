#include <iostream>
using namespace std;

int First(int *arr, int s, int e, int size, int k){ 
    if(s == size){   // Base case
        return -1;
    }
    if(arr[s] == k){ // Found the element
        return s;
    }
    return First(arr, s+1, e, size, k); // Return recursive result
}

int Last(int *arr, int s, int e, int size, int k){ 
    if(e < 0){   // Base case (searching backwards)
        return -1;
    }
    if(arr[e] == k){ // Found the element
        return e;
    }
    return Last(arr, s, e-1, size, k); // Return recursive result
}

int main() {
    int arr[10] = {1, 2, 3, 3, 3, 3, 4, 3, 10, 76};

    cout << "Index of first occurrence is " << First(arr, 0, 9, 10, 3) << endl;
    cout << "Index of last occurrence is " << Last(arr, 0, 9, 10, 3) << endl;

    return 0;
}
