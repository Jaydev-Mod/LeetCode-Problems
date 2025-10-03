class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>> grid;
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for(int row = 0; row < m; row++){
            for(int col : {0, n-1}){
                grid.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        for(int col = 0; col < n; col++){
            for(int row : {0, m-1}){
                grid.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!grid.empty()){
            int height = grid.top().first;
            int row = grid.top().second.first;
            int col = grid.top().second.second;
            grid.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + directions[i][0];
                int ncol = col + directions[i][1];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                    water += max(height - heightMap[nrow][ncol], 0);
                    grid.push({max(heightMap[nrow][ncol], height), {nrow, ncol}});
                    visited[nrow][ncol] = true;
                }
            }
        }
        return water;
    }
};