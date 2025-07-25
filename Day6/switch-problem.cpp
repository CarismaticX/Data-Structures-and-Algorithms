//Given a amount of money, deduce how many 100 rupee notes, 50 rupee notes, 20 rupee notes and 1 rupee notes you need 
//in order to have that amount of money 

#include <iostream>
using namespace std;

int main() {


    int n;
    cout<<"Enter the amount of money :"<<endl;
    cin>>n;


    switch(1){

        case 1: cout<<"number of 100 rupess notes :"<< (n/100)<<endl;
        n = n%100;
                   

        case 2: cout<< "number of 50 rupee notes : "<< (n/50) <<endl;
        n = n%50;


        case 3: cout<<"number of 20 rupee notes :"<< ( n/20)<<endl;
        n = n%20;

        case 4: cout<<"number of 1 rupee notes :"<< (n/1)<<endl;
        n = n%1;

        break;

    
    }
    

    return 0;
}