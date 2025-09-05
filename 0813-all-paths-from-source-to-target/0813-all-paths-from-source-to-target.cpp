class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& temp, int source, int target){
        temp.push_back(source);
        if(source == target){
            ans.push_back(temp);
        }else{
            for(int it : graph[source]){
                dfs(graph, ans, temp, it, target);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int target = graph.size()-1;
        dfs(graph, ans, temp, 0, target);
        return ans;
    }
};