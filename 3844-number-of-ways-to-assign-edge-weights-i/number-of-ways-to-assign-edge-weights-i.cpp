class Solution {
public:
    const int MOD = 1e9 + 7;
    int height = 0;

    vector<long long> fact, invFact;

    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res*a) % MOD;
            a = (a*a) % MOD;
            b >>= 1;
        }
        return res;
    }

    void init(int n) {
        fact.resize(n+1);
        invFact.resize(n+1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        invFact[n] = binpow(fact[n], MOD-2);

        for (int i = n; i >= 1; i--) {
            invFact[i-1] = (invFact[i] * i) % MOD;
        }
    }

    void dfs(vector<vector<int>>& adj, int node, int parent, int depth) {
        height = max(height, depth);

        for (int v : adj[node]) {
            if (v != parent) {
                dfs(adj, v, node, depth + 1);
            }
        }
    }

    int nCr(int n, int r) {
        return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;

        init(n);

        vector<vector<int>> adj(n+1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(adj, 1, -1, 0);

        int ans = 0;
        for (int i = 1; i <= height; i += 2) {
            ans = (ans + nCr(height, i)) % MOD;
        }

        return ans;
    }
};