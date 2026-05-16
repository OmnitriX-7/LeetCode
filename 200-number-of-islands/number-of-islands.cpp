class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j, int n, int m) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        vector<vector<int>> dv = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            for (auto& i : dv) {
                int nr = x + i[0];
                int nc = y + i[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    bfs(grid, vis, i, j, n, m);
                }
            }
        }
        return ans;
    }
};