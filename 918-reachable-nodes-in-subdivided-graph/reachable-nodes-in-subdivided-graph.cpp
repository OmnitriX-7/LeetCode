class Solution {
public:
    vector<vector<vector<int>>> construct(vector<vector<int>>& edges, int n) {
        vector<vector<vector<int>>> res(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            res[u].push_back({v, wt+1});
            res[v].push_back({u, wt+1});
        }
        return res;
    }

    vector<int> dijkstra(vector<vector<vector<int>>>& AdjList, int n) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, 0});

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!minh.empty()) {
            int dis = minh.top()[0];
            int node = minh.top()[1];
            minh.pop();
            if (dis > dist[node]) continue;

            for (auto e : AdjList[node]) {
                int x = e[0];
                int y = e[1];
                if (dist[x] > dis + y) {
                    dist[x] = dis + y;
                    minh.push({dist[x], x});
                }
            }
        }
        return dist;
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<vector<int>>> AdjList = construct(edges, n);
        vector<int> dist = dijkstra(AdjList, n);
        
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) ans += 1;
        }
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            long long a = (dist[u] > maxMoves) ? 0 : maxMoves - dist[u];
            long long b = (dist[v] > maxMoves) ? 0 : maxMoves - dist[v];
            ans += min((long long)w, a + b);
        }
        return ans;
    }
};