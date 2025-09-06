class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        int done = 0;
        for (int i = 0; i < m; i++) {
            if (!done) {
                if (obstacleGrid[i][0] == 0) ans[i][0] = 1;
                else done = 1;
            }
            else break;
        }

        done = 0;
        for (int i = 0; i < n; i++) {
            if (!done) {
                if (obstacleGrid[0][i] == 0) ans[0][i] = 1;
                else done = 1;
            }
            else break;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] != 1) {
                    ans[i][j] += ans[i-1][j] + ans[i][j-1];
                }
            }
        }
        return ans[m-1][n-1];
    }
};