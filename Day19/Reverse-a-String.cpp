#include <iostream>
using namespace std;

void reverse(char nam[], int n ){
    int s =0;
    int e =n-1;

    while(s<e){
        swap(nam[s++], nam[e--]);
    }
}

int getLength(char name[]){

    int count =0;
    for(int i=0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main() {

    char name[20];

    cout<<"Enter your name :"<<endl;
    cin>>name;

    cout<<"your name is ";
    cout<<name<<endl;
    int len = getLength(name);

    cout<<"Length:"<<len<<endl;
    reverse(name, len);


    cout<<"Your reverse name is:";
    cout<<name;
    

    return 0;
}