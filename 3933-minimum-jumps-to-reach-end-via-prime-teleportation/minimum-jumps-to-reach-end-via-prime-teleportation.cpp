class Solution {
    bool ip(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        unordered_set<int> ap;
        for (int x : nums) {
            if (ip(x)) ap.insert(x);
        }

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            for (int p = 2; p * p <= t; p++) {
                if (t % p == 0) {
                    if (ap.count(p)) adj[p].push_back(i);
                    while (t % p == 0) t /= p;
                }
            }
            if (t > 1 && ap.count(t)) {
                adj[t].push_back(i);
            }
        }

        queue<int> q;
        vector<int> d(n, -1);
        unordered_set<int> vp;

        q.push(0);
        d[0] = 0;

        while (!q.empty()) {
            int c = q.front();
            q.pop();

            if (c == n - 1) return d[c];

            if (c - 1 >= 0 && d[c - 1] == -1) {
                d[c - 1] = d[c] + 1;
                q.push(c - 1);
            }
            
            if (c + 1 < n && d[c + 1] == -1) {
                d[c + 1] = d[c] + 1;
                q.push(c + 1);
            }

            int v = nums[c];
            if (ap.count(v) && !vp.count(v)) {
                vp.insert(v);
                for (int nx : adj[v]) {
                    if (d[nx] == -1) {
                        d[nx] = d[c] + 1;
                        q.push(nx);
                    }
                }
            }
        }

        return -1;
    }
};