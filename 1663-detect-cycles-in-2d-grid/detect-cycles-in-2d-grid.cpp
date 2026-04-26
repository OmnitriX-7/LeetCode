class Solution {
public:
    int bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        char target = grid[i][j];
        vector<vector<int>> dv = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{i, j},{-1, -1}});

        while (!q.empty()) {
            auto [curr, parent] = q.front();
            int x = curr.first, y = curr.second;
            int pr = parent.first, pc = parent.second;
            q.pop();
            vis[x][y] = 1;
            for (int k = 0; k < 4; k++) {
                int nr = x + dv[k][0];
                int nc = y + dv[k][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == target) {
                    if (!vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({{nr, nc}, {x, y}});
                    }
                    else {
                        if (!(nr == pr && nc == pc)) {
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (bfs(grid, vis, i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};