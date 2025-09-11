class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for (auto edge : flights){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back({v, w});
        }

        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            vector<int> tempCost = cost;

            for(int i = 0; i < size; i++){
                int city = q.front().first;
                int currCost = q.front().second;
                q.pop();
                for(auto it : adjList[city]){
                    int next = it.first;
                    int price = it.second;
                    if(currCost + price < tempCost[next]){
                        tempCost[next] = currCost + price;
                    q.push({next, tempCost[next]});
                    }
                }
            }
            cost = tempCost;
            stops++;
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};