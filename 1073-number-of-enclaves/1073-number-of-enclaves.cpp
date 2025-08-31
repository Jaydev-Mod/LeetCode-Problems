class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (grid[i][j] == 1) {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + directions[i][0];
                int ncol = col + directions[i][1];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) {
                    continue;
                } else if (grid[i][j] == 1 && visited[i][j] != 1) {
                    count++;
                }
            }
        }
        return count;
    }
};