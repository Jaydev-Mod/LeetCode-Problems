class Solution {
    struct DSU {
        vector<int> parent;
        vector<set<int>> grid_stations;

        DSU(int n) {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            grid_stations.resize(n + 1);
            for (int i = 1; i <= n; ++i) {
                grid_stations[i].insert(i);
            }
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        void unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                if (grid_stations[root_i].size() <
                    grid_stations[root_j].size()) {
                    swap(root_i, root_j);
                }

                parent[root_j] = root_i;
                grid_stations[root_i].insert(grid_stations[root_j].begin(),
                                             grid_stations[root_j].end());
                grid_stations[root_j].clear();
            }
        }
    };

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU dsu(c);
        for (const auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }

        vector<int> result;
        for (const auto& query : queries) {
            int type = query[0];
            int x = query[1];
            int root_x = dsu.find(x);

            if (type == 1) {
                if (dsu.grid_stations[root_x].count(x)) {
                    result.push_back(x);
                } else if (dsu.grid_stations[root_x].empty()) {
                    result.push_back(-1);
                } else {
                    result.push_back(*dsu.grid_stations[root_x].begin());
                }
            } else {
                if (dsu.grid_stations[root_x].count(x)) {
                    dsu.grid_stations[root_x].erase(x);
                }
            }
        }
        return result;
    }
};