

#include <iostream>
using namespace std;

int main() {

    int a,b ;

    cout<<"Enter the value of a :";
    cout<<endl;
    cin>>a;


    cout<<"Enter the value of b :";
    cout<<endl;
    cin>>b;

    char ch;
    cout<<"Enter the operation you want to perfrom :";
    cout<<endl;
    cin>>ch;

    switch (ch)
    {
    case '+' : cout << (a+b);
    break;

    
    case '-' :cout<<(a-b);
    break;

    case '*' :cout<<(a*b);
    break;

    case '/' :cout<<(a/b);
    break;

    case '%' :cout<<(a%b);
    break;
         
    
    default: cout<<"Please Enter a valid operation to be performed";
        break;
    }
    

    return 0;
}