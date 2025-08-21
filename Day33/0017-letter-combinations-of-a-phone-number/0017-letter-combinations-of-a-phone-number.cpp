class Solution {
private:
    void solve(string digits, string mapping[], vector<string>& ans, string output, int index) {
        if(index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int j = 0; j < value.length(); j++) {   // use j for loop
            output.push_back(value[j]);
            solve(digits, mapping, ans, output, index+1); // move to next digit
            output.pop_back(); // backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) {
            return ans;
        }

        string output = "";
        int index = 0;

        string mapping[10] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(digits, mapping, ans, output, index);
        return ans;
    }
};
