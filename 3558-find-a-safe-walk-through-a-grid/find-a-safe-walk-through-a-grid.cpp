class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> max_health(n, vector<int>(m, -1));

        int start = health-grid[0][0];
        if (start < 0) return 0;

        priority_queue<vector<int>> maxh;
        maxh.push({start, 0, 0});

        max_health[0][0] = start;

        vector<vector<int>> dv = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while (!maxh.empty()){
            vector<int> curr = maxh.top();
            maxh.pop();
            int h = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == n-1 && c == m-1) return 1;

            if (h < max_health[r][c]) continue;

            for (int i = 0; i < 4; i++){
                int nr = r + dv[i][0];
                int nc = c + dv[i][1];
                if (nr >= 0 && nr < n && nc >=0 && nc < m){
                    int new_health = h - grid[nr][nc];
                    if (new_health > 0 && new_health > max_health[nr][nc]){
                        max_health[nr][nc] = new_health;
                        maxh.push({new_health, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};