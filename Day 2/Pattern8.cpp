// Print the Pattern
//      *
//     ***
//    ***** 
//   *******
//  *********
// ***********  
// ***********
//  *********
//   *******
//    ***** 
//     ***    
//      *
//This is the combination of last two patterns

#include <iostream>
using namespace std;

int main() {
    int n ;
    cout<<"Enter a number: ";
    cin>>n;
//This is the upper half 
     for(int i= 0 ; i<n ; i++){
        for(int j= 0 ; j<n-i-1 ; j++){
            cout<<" ";
        }

        for(int j= 0 ; j<2*i+1 ; j++){
            cout<<"*";
        }

        for(int j= 0 ; j<n-i-1 ; j++){
            cout<<" ";
        }
        cout<<endl;
    }



//Lower half of the Pattern
     for(int i = 0 ; i<n ; i++){
        for(int j=0; j<i;j ++){
            cout<<" ";
        }
        
        for(int j=0; j<2*(n-i)- 1;j ++){
            cout<<"*";
        }

        for(int j=0; j<i;j ++){
            cout<<" ";
        }

        cout<<endl;
    }

    

    return 0;
}