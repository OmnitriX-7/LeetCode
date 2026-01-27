class Solution {
public:
    vector<vector<vector<int>>> construct(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> res(n);
        for (auto& edge : edges) {
            res[edge[0]].push_back({edge[1], edge[2]});
            res[edge[1]].push_back({edge[0], edge[2]*2});
        }
        return res;
    }

    vector<int> dijkstra(vector<vector<vector<int>>>& AdjList, int n) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, 0});

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!minh.empty()) {
            int node = minh.top()[1];
            minh.pop();

            for (auto& x : AdjList[node]) {
                if (dist[x[0]] > dist[node]+x[1]) {
                    dist[x[0]] = dist[node]+x[1];
                    minh.push({dist[x[0]], x[0]});
                }
            }
        }
        return dist;
    }
    
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> AdjList = construct(n, edges);
        vector<int> final = dijkstra(AdjList, n);

        if (final[n-1] == INT_MAX) return -1;
        return final[n-1];
    }
};