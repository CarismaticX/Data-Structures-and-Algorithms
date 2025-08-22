//Problem - https://www.naukri.com/code360/problems/permutations-of-a-string_985254


#include <vector>
#include <string>
#include <algorithm> // Needed for sort()
using namespace std;

void solve(string &str, vector<string> &ans, int index) {
    if (index >= (int)str.length()) {
        ans.push_back(str);
        return;
    }

    for (int j = index; j < (int)str.length(); j++) {
        swap(str[index], str[j]);
        solve(str, ans, index + 1);
        swap(str[index], str[j]); // backtrack
    }
}

vector<string> generatePermutations(string &str) {
    vector<string> ans;
    solve(str, ans, 0);
    sort(ans.begin(), ans.end()); // Ensure lexicographical order
    return ans;
}
