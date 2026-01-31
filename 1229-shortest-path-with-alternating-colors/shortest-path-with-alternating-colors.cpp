class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : redEdges) adj[edge[0]].push_back({edge[1], 0});
        for (auto& edge : blueEdges) adj[edge[0]].push_back({edge[1], 1});

        vector<vector<int>> dist(n, vector<int>(2, -1));
        dist[0][0] = 0;
        dist[0][1] = 0;
        queue<pair<int, int>> q;
        q.push({0,0});
        q.push({0,1});

        while (!q.empty()){
            auto [u, prevColor] = q.front();
            q.pop();

            for (auto [v, edgeColor] : adj[u]){
                if (edgeColor != prevColor && dist[v][edgeColor] == -1){
                    dist[v][edgeColor] = dist[u][prevColor] + 1;
                    q.push({v, edgeColor});
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            int d1 = dist[i][0];
            int d2 = dist[i][1];
            if (d1 == -1) ans[i] = d2;
            else if (d2 == -1) ans[i] = d1;
            else ans[i] = min(d1, d2);
        }

        return ans;
    }
};