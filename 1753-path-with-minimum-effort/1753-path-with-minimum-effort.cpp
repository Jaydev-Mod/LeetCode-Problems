class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> effort(m, vector<int> (n, INT_MAX));
        effort[0][0] = 0;

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!pq.empty()){
            int curr_effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if((row == m-1) && (col == n-1)) return curr_effort;

            for(int i = 0; i < 4; i++){
    int nrow = row + dirs[i][0];
    int ncol = col + dirs[i][1];
    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
        int new_effort = max(abs(heights[nrow][ncol] - heights[row][col]), curr_effort);
        if(new_effort < effort[nrow][ncol]){
            effort[nrow][ncol] = new_effort;
            pq.push({new_effort, {nrow, ncol}});
        }
    }
}
        }
        return 0;
    }
};