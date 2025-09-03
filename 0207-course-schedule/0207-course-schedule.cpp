class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> topo;
        vector<vector<int>> adjList(V);
        vector<int> inDegree(V, 0);
        for (auto edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adjList[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (topo.size() == V) {
            return true;
        }

        return false;
    }
};