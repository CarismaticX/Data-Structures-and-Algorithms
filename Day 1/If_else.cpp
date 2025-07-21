#include <iostream>
using namespace std;

// int main(){
//     int a;
//     cin>>a;
//     cout << "Value of a is :" << a << endl;
// }

int main (){
    int a,b;

    cout<<"Enter the value of a :"  <<endl;
    cin>>a;
    cout<<"Enter the value of b :" << endl;
    cin>>b;

    if(a>b){
        cout<<"a is greater than b" <<endl;
    }else if(b>a){
        cout<<"b is greater than a "<<endl;
    }
    else{
        cout<<"both are equal"<<endl;
    }
};