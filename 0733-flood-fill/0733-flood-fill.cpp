class Solution {
public:
    void bfs(int row, int col, int color, int currColor, vector<vector<int>>& image, vector<vector<int>>& visited){
        int m = image.size();
        int n = image[0].size();
        visited[row][col] = 1;
        image[row][col] = color;
        queue<pair<int, int>> q;
        q.push({row, col});
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == currColor && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int currColor = image[sr][sc];
        vector<vector<int>> visited(m, vector<int> (n, 0));
        bfs(sr, sc, color, currColor, image, visited);
        return image;
    }
};