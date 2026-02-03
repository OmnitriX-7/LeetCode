class Solution {
public:
    vector<long long> dijkstra(vector<vector<pair<int, int>>>& adj, int src){
        int n = adj.size();
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minh;
        minh.push({0, src});

        while (!minh.empty()){
            long long d = minh.top().first;
            int u = minh.top().second;
            minh.pop();

            if (d > dist[u]) continue;

            for (auto [v, nd] : adj[u]){
                if (dist[v] > dist[u] + nd){
                    dist[v] = dist[u] + nd;
                    minh.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> rev(n);
        for (auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> d1 = dijkstra(adj, src1);
        vector<long long> d2 = dijkstra(adj, src2);
        vector<long long> d3 = dijkstra(rev, dest);

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++){
            long long x = d1[i] == LLONG_MAX ? -1 : d1[i];
            long long y = d2[i] == LLONG_MAX ? -1 : d2[i];
            long long z = d3[i] == LLONG_MAX ? -1 : d3[i];
            
            if (x == -1 || y == -1 || z == -1) continue;

            ans = min<long long>(ans, x + y + z);
        }

        if (ans == LLONG_MAX) return -1;
        return ans;
    }
};