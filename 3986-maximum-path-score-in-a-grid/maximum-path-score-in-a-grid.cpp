class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        dp[0][0][0] = 0;
        
        int dv[2][2] = {{0,1}, {1,0}};

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int max_cost = i + j;
                for (int c = 0; c <= min(k, max_cost); c++){
                    if (dp[i][j][c] == -1) continue;
                    
                    for (int d = 0; d < 2; d++){
                        int ni = i + dv[d][0];
                        int nj = j + dv[d][1];
                        
                        if (ni >= n || nj >= m) continue;
                        
                        int add = 0;
                        if (grid[ni][nj] > 0) add += 1;
                        
                        if (c + add <= k) {
                            dp[ni][nj][c+add] = max(dp[ni][nj][c+add], dp[i][j][c]+grid[ni][nj]);
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++){
            ans = max(ans, dp[n-1][m-1][c]);
        }
        return ans;
    }
};