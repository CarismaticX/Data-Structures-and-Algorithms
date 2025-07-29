//print fibbonaci number 

int fibbonacci(int n ){
    if(n ==1 || n ==2 ){
        return n-1;
    }

    int ans = 0, a =0 , b = 1;

    for(int i =3; i<=n; i++){
        ans = a + b;
        a =b; 
        b = ans;
    }
    return ans;

}

#include <iostream>
using namespace std;

int main() {

    int n;
    cin>>n;

    cout<<fibbonacci(n)<<endl;
    

    return 0;
}