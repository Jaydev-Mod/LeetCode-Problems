class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited, vector<vector<int>> directions){
        int m = board.size();
        int n = board[0].size();
        visited[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int nrow = row + directions[i][0];
            int ncol = col + directions[i][1];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol]=='O' && !visited[nrow][ncol]){
                dfs(nrow, ncol, board, visited, directions);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
         for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                dfs(0, j, board, visited, directions);
            }
            if (board[m-1][j] == 'O' && !visited[m-1][j]) {
                dfs(m-1, j, board, visited, directions);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, board, visited, directions);
            }
            if (board[i][n-1] == 'O' && !visited[i][n-1]) {
                dfs(i, n-1, board, visited, directions);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]!=1 && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};