class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (auto dir : directions) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    bfs(row, col, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};