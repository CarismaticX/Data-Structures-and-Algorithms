//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int a = 0, b = n - 1;
        
        // Step 1: Find potential celebrity
        while (a < b) {
            if (mat[a][b] == 1) 
                a++;   // a knows b → a not celebrity
            else 
                b--;   // a doesn’t know b → b not celebrity
        }
        
        // Step 2: Verify candidate
        int cand = a;
        for (int i = 0; i < n; i++) {
            if (i != cand) {
                if (mat[cand][i] == 1 || mat[i][cand] == 0)
                    return -1;  // candidate fails
            }
        }
        return cand;
    }
};
