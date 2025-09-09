class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n+1);
        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adjList[u].push_back({v, w});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            // if(node == n) return distance;
            if(distance > dist[node]) continue;
            for(auto it : adjList[node]){
                int weight = it.second;
                int neighbor = it.first;
                if(distance + weight < dist[neighbor]){
                    dist[neighbor] = distance + weight;
                    pq.push({dist[neighbor], neighbor});
                } 
            }
        }
        int minTime = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            minTime = max(minTime, dist[i]);
        }
        return minTime;
    }
};