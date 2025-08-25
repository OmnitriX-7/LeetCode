class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({dist[0][0], 0, 0});

        vector<vector<int>> dr = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!minh.empty()) {
            auto curr = minh.top();
            int x = curr[0], y = curr[1], z = curr[2];
            minh.pop();

            if (y == n-1 && z == m-1) return x;

            if (x > dist[y][z]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = y + dr[i][0], nc = z + dr[i][1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    continue;
                }
                int nv = x + grid[nr][nc];
                if (nv < dist[nr][nc]) {
                    dist[nr][nc] = nv;
                    minh.push({dist[nr][nc], nr, nc});
                }
            }
        }
        return -1;
    }
};