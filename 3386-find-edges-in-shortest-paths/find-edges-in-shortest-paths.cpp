using ll = long long;

class Solution {
public:
    vector<ll> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        vector<ll> dist(V, LLONG_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;  

            for (auto [v, w] : adj[u]) {
                if (dist[u] == LLONG_MAX) continue; 

                ll nd = dist[u] + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<ll> dist_0 = dijkstra(n, adj, 0);
        vector<ll> dist_n = dijkstra(n, adj, n-1);

        vector<bool> ans(edges.size());

        for (int i = 0; i < edges.size(); i++){
            auto &e = edges[i];

            if (dist_0[e[0]] == LLONG_MAX || dist_n[e[1]] == LLONG_MAX)
                continue;
            if (dist_0[e[1]] == LLONG_MAX || dist_n[e[0]] == LLONG_MAX)
                continue;

            ll d1 = dist_0[e[0]] + e[2] + dist_n[e[1]];
            ll d2 = dist_0[e[1]] + e[2] + dist_n[e[0]];

            if (d1 == dist_0[n-1] || d2 == dist_0[n-1])
                ans[i] = true;
            else
                ans[i] = false;
        }
        return ans;
    }
};
