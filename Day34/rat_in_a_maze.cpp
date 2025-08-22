//Problem - https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1&selectedLang=python3


class Solution {
    
private:
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze) {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1) {
            return true;
        }
        return false;
    }

    void solve(vector<vector<int>>& maze, int n, int srcx, int srcy, vector<string>& ans, vector<vector<int>>& visited, string path) {
        
        if (srcx == n - 1 && srcy == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[srcx][srcy] = 1;

        // Down
        int newx = srcx + 1;
        int newy = srcy;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('D');
            solve(maze, n, newx, newy, ans, visited, path);
            path.pop_back();
        }

        // Left
        newx = srcx;
        newy = srcy - 1;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('L');
            solve(maze, n, newx, newy, ans, visited, path);
            path.pop_back();
        }

        // Up
        newx = srcx - 1;
        newy = srcy;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('U');
            solve(maze, n, newx, newy, ans, visited, path);
            path.pop_back();
        }

        // Right
        newx = srcx;
        newy = srcy + 1;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('R');
            solve(maze, n, newx, newy, ans, visited, path);
            path.pop_back();
        }
        
         visited[srcx][srcy] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        if (maze[0][0] == 0) {
            return ans;
        }

        int srcx = 0, srcy = 0;
        int n = maze.size();

        vector<vector<int>> visited = maze;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }

        string path = "";
        solve(maze, n, srcx, srcy, ans, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
