class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    pq.push({0, i, j});
                }
            }
        }

        int ans = -1;
        vector<vector<int>> dv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            int d = curr[0];
            int x = curr[1];
            int y = curr[2];
            pq.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dv[i][0];
                int ny = y + dv[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({d + 1, nx, ny});
                    ans = max(ans, d + 1);
                }
            }
        }
        return ans;
    }
};