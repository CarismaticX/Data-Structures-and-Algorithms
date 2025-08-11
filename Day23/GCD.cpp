#include <bits/stdc++.h>
using namespace std;

// Function to find GCD using Euclid's Algorithm
int gcd(int a, int b) {
    
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }

    while(a!=b){
        if(a>b){
            a = a-b;

        }
        else{
            b = b-a;
        }
    }
    
    return a;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
