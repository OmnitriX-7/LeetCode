class Solution {
    vector<vector<int>> adj;
    vector<int> count;
    vector<int> res;
    int nodes;

    void dfs1(int u, int p, int d) {
        res[0] += d;
        count[u] = 1;
        for (auto& v : adj[u]) {
            if (v != p) {
                dfs1(v, u, d+1);
                count[u] += count[v];
            }
        }
    }

    void dfs2(int u, int p) {
        for (auto& v : adj[u]) {
            if (v != p) {
                res[v] = res[u]-count[v] + nodes-count[v];
                dfs2(v, u);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        nodes = n;
        adj.resize(n);
        count.resize(n, 0);
        res.resize(n, 0);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs1(0, -1, 0);
        dfs2(0, -1);

        return res;
    }
};