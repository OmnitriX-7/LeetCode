class Solution {
public:
    vector<vector<vector<int>>> ConstructAdj(vector<vector<int>>& times, int n) {
        vector<vector<vector<int>>> res(n+1);
        for (auto& edge : times) {
            int src = edge[0];
            int target = edge[1];
            int wt = edge[2];
            res[src].push_back({target, wt});
        }
        return res;
    }

    vector<int> dijkstra(vector<vector<vector<int>>>& edges, int src, int n) {
        vector<int> dist(n+1, INT_MAX);
        dist[src] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, src});

        while (!minh.empty()) {
            int top = minh.top()[1];
            minh.pop();

            for (auto& x : edges[top]) {
                int node = x[0];
                int weight = x[1];

                if (dist[node] > dist[top]+weight) {
                    dist[node] = dist[top]+weight;
                    minh.push({dist[node], node});
                }
            }
        }
        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> edges = ConstructAdj(times, n);
        vector<int> res = dijkstra(edges, k, n);

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (res[i] == INT_MAX) return -1;
            ans = max(ans,res[i]);
        }

        return ans;
    }
};