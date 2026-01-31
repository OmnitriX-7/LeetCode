class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist(n+1, -1);
        dist[1] = 0;
        vector<int> dist2(n+1, -1);
        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty()){
            auto [u, t] = q.front();
            q.pop();

            int wait = 0;
            if ((t/change) % 2 == 1){
                wait += ((t/change + 1) * change) - t;
            }

            int nextTime = t + wait + time;

            for (auto v : adj[u]){
                if (dist[v] == -1){
                    dist[v] = nextTime;
                    q.push({v, nextTime});
                }
                else if (dist2[v] == -1 && nextTime > dist[v]){
                    dist2[v] = nextTime;
                    q.push({v, nextTime});
                }
            }
        }

        return dist2[n];
    }
};