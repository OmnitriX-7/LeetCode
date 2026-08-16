class Solution {
public:
    int find(int u, vector<int>& parent) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u], parent);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int w = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({w, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        int ans = 0;
        int total_edge = 0;

        for (auto& e : edges) {
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;

            int root_u = find(u, parent);
            int root_v = find(v, parent);

            if (root_u != root_v) {
                ans += w;
                parent[root_u] = root_v;
                total_edge++;
                
                if (total_edge == n-1) break;
            }
        }

        return ans;
    }
};