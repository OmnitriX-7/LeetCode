class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, 0, 0});

        vector<vector<int>> dr = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!minh.empty()) {
            auto curr = minh.top();
            minh.pop();
            int x = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (x >= time[r][c]) continue;
            time[r][c] = x;

            if (r == n-1 && c == m-1) return x;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i][0], nc = c + dr[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && time[nr][nc] == INT_MAX) {
                    int nv = max(moveTime[nr][nc], x) + 1;
                    minh.push({nv, nr, nc});
                }
            }
        }
        return -1;
    }
};
