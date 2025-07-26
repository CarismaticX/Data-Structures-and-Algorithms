#include <iostream>
#include <climits>
using namespace std;

int getMax(int arr[], int n) {
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int getMin(int arr[], int n) {
    int mini = INT_MAX;
    for(int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
    }
    return mini;
}



int main() {

    int size;
    cin>>size;

    int num[100];

    for (int i=0; i<size; i++){
        cin>>num[i];
    }

    cout << "Maximum element is: " << getMax(num, size) << endl;
    cout << "Minimum element is: " << getMin(num, size) << endl;
    

    return 0;
}
