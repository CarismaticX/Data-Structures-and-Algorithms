//Print the total number of 1's(set bits) in a and b binary form;

#include <iostream>
using namespace std;

int bits(int n){
    int ans =0 ;
    while(n>0){
        if(n & 1){
            ans++;
       
        }
         n = n>>1;
    }
    return ans;

}

int main() {
    int a,b;
    cin>>a>>b;

    cout<<"the number of set bits are : "<<(bits(a) + bits(b))<<endl;

    return 0;
}