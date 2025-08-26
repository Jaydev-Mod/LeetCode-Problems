class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for(int i = 1; i <= isConnected.size(); i++){
                if(isConnected[i-1][temp-1] == 1 && !visited[i]){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> visited(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                bfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};