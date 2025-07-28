class Solution {
public:

    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        queue<pair<int,int>> land;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        bool found = false;
        for (int i = 0; i < m && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    land.push({i,j});
                    visited[i][j] = 1;
                    found = true;
                    break;
                }
            }
        }

        vector<pair<int,int>> direction = {{0,-1}, {0,1}, {-1,0}, {1,0}};

        while (!land.empty()) {
            auto [x,y] = land.front();
            land.pop();

            for (auto [i,j] : direction) {
                int nr = x + i;
                int nj = y + j;

                if (nr < 0 || nj < 0 || nr >= m || nj >= n || grid[nr][nj] == 0) {
                    peri++;
                }
                
                else if (!visited[nr][nj]) {
                    visited[nr][nj] = 1;
                    land.push({nr,nj});
                }
            }
        }
        
        return peri;
    }
};