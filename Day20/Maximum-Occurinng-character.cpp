//Problem - https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        
        int arr[26] ={0};
        int number = 0;
        
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            if(ch>='a' && ch<='z' ){
                number = ch - 'a';
            }
            else {
                number = ch - 'A';
            }
            arr[number]++;
        }
        
        int ans = 0; 
        int maxi= -1;
        
        for(int i = 0; i<26; i++){
            if(maxi<arr[i]){
                ans = i;
                maxi = arr[i];
            }
        }
        
        return 'a'+ans;
        
    }
};