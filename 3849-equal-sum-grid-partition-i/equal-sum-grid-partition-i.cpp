class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid1) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<long long>> grid(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) grid[i][j] = grid1[i][j];
        }

        for (int i = 1; i < m; i++) {
            grid[0][i] += grid[0][i-1];
        }
        for (int i = 1; i < n; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        for (int i = 0; i < n-1; i++) {
            long long up_sum = grid[i][m-1];
            long long down_sum = grid[n-1][m-1] - up_sum;
            if (up_sum == down_sum) return 1;
        }
        for (int i = 0; i < m-1; i++) {
            long long left_sum = grid[n-1][i];
            long long right_sum = grid[n-1][m-1] - left_sum;
            if (left_sum == right_sum) return 1;
        }

        return 0;
    }
};