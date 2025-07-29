// Print pattern 
// A
// A B
// A B C
// A B C D
// A B C D E
// A B C D E F

#include <iostream>
using namespace std;

int main() {

    int n ;
    cin>>n;
    
    for(int i =0; i<n; i++) {

        for(char ch = 'A' ; ch<='A'+ i; ch++){
            cout<<ch<<" ";
        }
        cout<<endl;

    }

    return 0;
}