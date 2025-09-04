class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();\
        vector<int> inDegree(n, 0);
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            for (int it : graph[i]) {
                adjList[it].push_back(i);
                inDegree[i]++;
            }
        }

        vector<int> ans;
        queue<int> q;
        for(int i = 0;i < n; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int it : adjList[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};