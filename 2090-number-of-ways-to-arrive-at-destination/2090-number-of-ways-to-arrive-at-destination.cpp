class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adjList(n);
        for (auto road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9 + 7);

        while (!pq.empty()) {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > dist[node]) {
                continue;
            }

            for (auto it : adjList[node]) {
                int neighbor = it.first;
                long long currTime = it.second;
                long long newTime = time + currTime;

                if (newTime < dist[neighbor]) {
                    dist[neighbor] = time + currTime;
                    ways[neighbor] = ways[node] % mod;
                    pq.push({dist[neighbor], neighbor});
                } else if (time + currTime == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};