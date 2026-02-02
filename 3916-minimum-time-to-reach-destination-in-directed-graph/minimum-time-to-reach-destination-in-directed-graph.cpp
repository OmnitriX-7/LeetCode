class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2], e[3]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long t = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (t > dist[u]) continue;
            if (u == n - 1) return (int)t;

            for (auto& edge : adj[u]) {
                int v = edge[0];
                int s = edge[1];
                int e = edge[2];

                long long dep = max<long long>(t, (long long)s);

                if (dep <= e) {
                    long long arrival = dep + 1;
                    if (arrival < dist[v]) {
                        dist[v] = arrival;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        return -1;
    }
};