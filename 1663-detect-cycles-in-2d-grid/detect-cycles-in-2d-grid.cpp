class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<char>>& grid, int x, int y, int fromX, int fromY, char target) {
        visited[x][y] = true;

        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (auto& dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) continue;

            if (visited[nx][ny]) {
                // If it's visited and NOT the parent → cycle found
                if (nx != fromX || ny != fromY) return true;
            } else {
                if (dfs(grid, nx, ny, x, y, target)) return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j])) return true;
                }
            }
        }
        return false;
    }
};
