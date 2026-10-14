class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n <= 0 || m <= 0) return 0;
        if (grid[0][0] == -1 || grid[n - 1][m - 1] == -1) return 0;

        int T = (n - 1) + (m - 1);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];

        for (int t = 1; t <= T; ++t) {
            vector<vector<int>> next_dp(n, vector<int>(n, -1));
            int min_r = max(0, t - (m - 1));
            int max_r = min(n - 1, t);

            for (int r1 = min_r; r1 <= max_r; ++r1) {
                int c1 = t - r1;
                if (grid[r1][c1] == -1) continue;

                for (int r2 = min_r; r2 <= max_r; ++r2) {
                    int c2 = t - r2;
                    if (grid[r2][c2] == -1) continue;

                    int max_prev = -1;
                    for (int pr1 = r1 - 1; pr1 <= r1; ++pr1) {
                        for (int pr2 = r2 - 1; pr2 <= r2; ++pr2) {
                            if (pr1 >= 0 && pr1 < n && pr2 >= 0 && pr2 < n) {
                                if (dp[pr1][pr2] != -1) {
                                    max_prev = max(max_prev, dp[pr1][pr2]);
                                }
                            }
                        }
                    }

                    if (max_prev != -1) {
                        int val = (r1 == r2) ? grid[r1][c1] : (grid[r1][c1] + grid[r2][c2]);
                        next_dp[r1][r2] = max_prev + val;
                    }
                }
            }
            dp = move(next_dp);
        }

        return dp[n - 1][n - 1] == -1 ? 0 : dp[n - 1][n - 1];
    }
};