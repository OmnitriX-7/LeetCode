class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> col(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (col[i] != -1) continue;
            col[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (col[v] == -1) {
                        col[v] = col[u] ^ 1;
                        q.push(v);
                    } else if (col[v] == col[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for (auto &e : dislikes) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        return isBipartite(adj);
    }
};
