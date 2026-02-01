class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0,0,0});

        vector<vector<int>> dv = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while (!minh.empty()){
            vector<int> curr = minh.top();
            minh.pop();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == n-1 && c == m-1) return t;

            if (t > minTime[r][c]) continue;

            for (int i = 0; i < 4; i++){
                int nr = r + dv[i][0];
                int nc = c + dv[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int new_time;
                    if (grid[nr][nc] <= t) new_time = t+1;
                    else{
                        if ((grid[nr][nc]-t) % 2 == 0) new_time = grid[nr][nc] + 1;
                        else new_time = grid[nr][nc];
                    }

                    if (new_time < minTime[nr][nc]){
                        minTime[nr][nc] = new_time;
                        minh.push({new_time, nr, nc});
                    }
                }
            }
        }
        
        return -1;
    }
};