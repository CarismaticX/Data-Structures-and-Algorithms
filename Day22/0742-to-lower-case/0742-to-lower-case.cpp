class Solution {
public:
    string toLowerCase(string s) {

        string temp;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch - 'A' + 'a';  // convert uppercase to lowercase
            }
            temp.push_back(ch); // push unchanged or converted char
        }

        return temp;
        
    }
};