class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    grid[nr][nc] == '1' && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
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