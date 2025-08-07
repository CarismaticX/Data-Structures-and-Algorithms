//Problem- https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633

#include <bits/stdc++.h> 

char toLowerCase(char ch){
    if(ch >= 'a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch-'A' + 'a';
        return temp;
    }
}
bool checkPalindrome(string s)
{
    // Write your code here.
    int st =0;
    int e = s.size()-1;

    while(st<=e){
        if(!isalnum(s[st])){
            st++;
        }else if(!isalnum(s[e])){
            e--;
        }
        else{
            if(toLowerCase(s[st]) != toLowerCase(s[e])) {
                return false;
            }
            st++;
        e--;

        }
        
    }
    return 1;
}