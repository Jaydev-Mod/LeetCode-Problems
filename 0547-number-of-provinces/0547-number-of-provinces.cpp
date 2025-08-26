class Solution {
public:
    void bfs(int node, vector<vector<int>>& adjLs, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int it : adjLs[temp]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i, adjLs, visited);
                count++;
            }
        }
        return count;
    }
};