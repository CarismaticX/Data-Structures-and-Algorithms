#include <iostream>
using namespace std;
int Power(int a, int b){

    //base case
    if(b ==0 ){
        return 1;
    }
    if(b ==1){
        return a;
    }

    //Recursive call

    int ans = Power(a, b/2);

    if(b%2 ==0){//b is even
        ans = ans * ans;
    }else{
        //odd
        ans = a * ans * ans;
    }
}

int main() {
    
    int a,b;
    cin>>a>>b;


    cout<<Power(a,b);




    return 0;
}