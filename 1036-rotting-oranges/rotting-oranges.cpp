class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int time = 0;
        vector<pair<int, int>> directions = {{0,-1}, {0,1}, {1,0}, {-1,0}}; //left, right, up, down

        while (!q.empty()) {
            int z = q.size();
            bool rott = false;

            for (int k = 0; k < z; k++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [i, j] : directions) {
                    int nx = x+i;
                    int ny = y+j;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                        rott = true;
                    }
                }
            }
            if (rott) time++;
        }

        if (fresh) return -1;
        return time;
    }
};