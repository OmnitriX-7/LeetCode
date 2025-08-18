class Solution {
public:
    vector<vector<vector<int>>> construct(vector<vector<int>>& edges, int n) {
        vector<vector<vector<int>>> res(n);
        for (auto& it : edges) {
            res[it[0]].push_back({it[1], it[2]});
            res[it[1]].push_back({it[0], it[2]});
        }
        return res;
    }

    int dijkstra(int src, vector<vector<vector<int>>>& AdjList, int n,  int distanceThreshold) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, src});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!minh.empty()) {
            int dis = minh.top()[0];
            int node = minh.top()[1];
            minh.pop();

            if (dis > dist[node]) continue;

            for (auto& x : AdjList[node]) {
                int to = x[0], d = x[1];
                
                if (dist[to] > dist[node]+d) {
                    dist[to] = dist[node]+d;
                    if (dist[to] <= distanceThreshold) {
                        minh.push({dist[to], to});
                    }
                }
            }
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (i != src && dist[i] <= distanceThreshold)
                total++;
        }
        return total;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<vector<int>>> AdjList = construct(edges, n);

        int final = -1;
        int cnt = INT_MAX;
        for (int i = 0; i < n; i++) {
            int num = dijkstra(i, AdjList, n, distanceThreshold);
            if (num <= cnt) {
                cnt = num;
                final = i;
            }
        }
        return final;
    }
};