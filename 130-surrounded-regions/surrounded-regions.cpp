class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<pair<int, int>> region;
        bool safe = false;

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            region.push_back({x,y});

            if (x == 0 || y == 0 || x == m-1 || y == n-1) {
                safe = true;
            }

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] && board[nx][ny] == 'O') {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        if (!safe) {
            for (auto [i,j] : region) {
                board[i][j] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    bfs(board, visited, i, j);
                }
            }
        }
    }
};