class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<priority_queue<int, vector<int>, greater<int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            
            if (vals[u] > 0) {
                adj[v].push(vals[u]);
                if (adj[v].size() > k) adj[v].pop();
            }

            if (vals[v] > 0) {
                adj[u].push(vals[v]);
                if (adj[u].size() > k) adj[u].pop();
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int curr = vals[i];
            while (!adj[i].empty()) {
                curr += adj[i].top();
                adj[i].pop();
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};