#include <iostream>
using namespace std;

bool isEven(int a){

    if(a&1){ //odd
        return 0;
    }
    //even
    else{
        return 1;
    }

}

int main() {

    int num;
    cin>>num;

    if(isEven(num)){
        cout<<"given number is Even"<<endl;
    }
    else{
        cout<<"Given number is Odd"<<endl;
    }
    

    return 0;
}