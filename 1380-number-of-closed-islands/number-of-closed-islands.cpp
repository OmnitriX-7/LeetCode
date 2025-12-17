class Solution {
public:
    bool bfs(int i, int j, vector<vector<int>>& g, vector<vector<int>>& vis) {
        int n = g.size(), m = g[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;

        bool ok = true;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();

            if (x==0 || y==0 || x==n-1 || y==m-1)
                ok = false;

            for (int d=0; d<4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx>=0 && ny>=0 && nx<n && ny<m &&
                    g[nx][ny]==0 && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        return ok;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && grid[i][j] == 0){
                    if (bfs(i, j, grid, vis)) cnt++;
                }
            }
        }

        return cnt;
    }
};