class Solution {
public:
    int bfs(int i, vector<int>& vis, vector<vector<int>>& adj, vector<int>& source, vector<int>& target) {
        vector<int> x, y;
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            x.push_back(source[top]);
            y.push_back(target[top]);

            for (auto& v : adj[top]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        int c = 0;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int j = 0, k = 0;
        while (j < x.size() && k < y.size()) {
            if (x[j] == y[k]) {
                c++;
                j++;
                k++;
            } else if (x[j] < y[k]) {
                j++;
            } else {
                k++;
            }
        }
        return x.size() - c;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> adj(n);
        for (auto& e : allowedSwaps) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans += bfs(i, vis, adj, source, target);
            }
        }
        return ans;
    }
};