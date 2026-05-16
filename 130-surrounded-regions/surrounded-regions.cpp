class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int done = 0;
        vector<vector<int>> dv = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<pair<int, int>> cors;
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            cors.push_back({x,y});

            if (x == 0 || x == n-1 || y == 0 || y == m-1) done = 1;

            for (auto& i : dv) {
                int nr = x + i[0];
                int nc = y + i[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && !vis[nr][nc]) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        if (!done) {
            for (auto& [x,y] : cors) {
                board[x][y] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    bfs(board, vis, i, j);
                }
            }
        }
    }
};