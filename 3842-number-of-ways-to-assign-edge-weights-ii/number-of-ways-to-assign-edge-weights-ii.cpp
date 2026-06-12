using namespace std;

class Solution {
    long long binpow(long long a, long long b) {
        long long res = 1;
        long long mod = 1e9 + 7;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    void dfs(int u, int p, int d, vector<vector<int>>& adj, vector<vector<int>>& up, vector<int>& depth) {
        up[u][0] = p;
        depth[u] = d;
        for (int i = 1; i < 20; ++i) {
            if (up[u][i-1] != -1) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            } else {
                up[u][i] = -1;
            }
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d+1, adj, up, depth);
            }
        }
    }

    int get_lca(int u, int v, vector<vector<int>>& up, vector<int>& depth) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        
        for (int i = 19; i >= 0; --i) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        for (int i = 19; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> up(n+1, vector<int>(20, -1));
        vector<int> depth(n+1, 0);

        dfs(1, -1, 0, adj, up, depth);

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int lca = get_lca(u, v, up, depth);
            int dist = depth[u] + depth[v] - 2*depth[lca];
            ans.push_back(binpow(2, dist-1));
        }
        return ans;
    }
};