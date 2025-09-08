class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (n == 1)
            return 1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                                    {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!q.empty()) {
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nrow = row + dirs[i][0];
                int ncol = col + dirs[i][1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && distance + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = distance + 1;
                    if ((nrow == n - 1) && (ncol == n - 1))
                        return dist[nrow][ncol];
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};