class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n));
        queue<pair<pair<int, int>, int>> q;
        int countFresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    countFresh++;
            }
        }

        int time = 0;
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int count = 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            time = max(time, tm);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + directions[i][0];
                int ncol = col + directions[i][1];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2) {
                    visited[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, tm + 1});
                    count++;
                }
            }
        }
        if (countFresh != count) {
            return -1;
        } else {
            return time;
        }
    }
};