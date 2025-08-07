class Solution {
private:
    bool valid(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
        return false;
    }

    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            return ch;
        } else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkPalindrome(string a) {
        int st = 0;
        int e = a.length() - 1;

        while (st <= e) {
            if (!isalnum(a[st])) {
                st++;
            } else if (!isalnum(a[e])) {
                e--;
            } else {
                if (a[st] != a[e]) {
                    return false;
                }
                st++;
                e--;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        string temp = "";

        for (int j = 0; j < s.length(); j++) {
            if (valid(s[j])) {
                temp.push_back(s[j]);
            }
        }

        for (int i = 0; i < temp.length(); i++) {
            temp[i] = toLowerCase(temp[i]);
        }

        return checkPalindrome(temp);
    }
};
