using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        queue<pair<int, int>> q;
        q.push({0,0});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n-1 && y == m-1) return 1;

            if (grid[x][y] == 1) {
                if (y+1 < m && !vis[x][y+1] && (grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5)) { vis[x][y+1] = 1; q.push({x, y+1}); }
                if (y-1 >= 0 && !vis[x][y-1] && (grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6)) { vis[x][y-1] = 1; q.push({x, y-1}); }
            }
            else if (grid[x][y] == 2) {
                if (x+1 < n && !vis[x+1][y] && (grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6)) { vis[x+1][y] = 1; q.push({x+1, y}); }
                if (x-1 >= 0 && !vis[x-1][y] && (grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4)) { vis[x-1][y] = 1; q.push({x-1, y}); }
            }
            else if (grid[x][y] == 3) {
                if (y-1 >= 0 && !vis[x][y-1] && (grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6)) { vis[x][y-1] = 1; q.push({x, y-1}); }
                if (x+1 < n && !vis[x+1][y] && (grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6)) { vis[x+1][y] = 1; q.push({x+1, y}); }
            }
            else if (grid[x][y] == 4) {
                if (x+1 < n && !vis[x+1][y] && (grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6)) { vis[x+1][y] = 1; q.push({x+1, y}); }
                if (y+1 < m && !vis[x][y+1] && (grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5)) { vis[x][y+1] = 1; q.push({x, y+1}); }
            }
            else if (grid[x][y] == 5) {
                if (x-1 >= 0 && !vis[x-1][y] && (grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4)) { vis[x-1][y] = 1; q.push({x-1, y}); }
                if (y-1 >= 0 && !vis[x][y-1] && (grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6)) { vis[x][y-1] = 1; q.push({x, y-1}); }
            }
            else if (grid[x][y] == 6) {
                if (x-1 >= 0 && !vis[x-1][y] && (grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4)) { vis[x-1][y] = 1; q.push({x-1, y}); }
                if (y+1 < m && !vis[x][y+1] && (grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5)) { vis[x][y+1] = 1; q.push({x, y+1}); }
            }
        }

        return 0;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vis[0][0] = 1;
        return bfs(grid, vis, n, m);
    }
};