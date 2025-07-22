// Print 
// F
// E F
// D E F
// C D E F
// B C D E F
// A B C D E F

#include <iostream>
using namespace std;

int main() {

    int n; 
    cin>>n;

    for(int i=0; i<n; i++){
        for(char ch = 'F'- i; ch<='F'; ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }

//for n number you can do it as 'A' + n -i 


    

    return 0;
}