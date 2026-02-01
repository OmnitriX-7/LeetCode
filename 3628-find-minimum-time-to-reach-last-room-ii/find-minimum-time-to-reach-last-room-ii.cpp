class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        
        minh.push({0, 0, 0});
        time[0][0] = 0;
        
        vector<vector<int>> dv = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!minh.empty()) {
            vector<int> curr = minh.top();
            minh.pop();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            if (t > time[r][c]) continue;
            
            if (r == n-1 && c == m-1) return t;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dv[i][0];
                int nc = c + dv[i][1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int wait = ((nr + nc) % 2 == 1) ? 1 : 2;
                    int nv = max(moveTime[nr][nc], t) + wait;
                    
                    if (nv < time[nr][nc]) {
                        time[nr][nc] = nv;
                        minh.push({nv, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};