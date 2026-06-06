class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) dp[i][j] += dp[i-1][j];
                else if (j == triangle[i].size()-1) dp[i][j] += dp[i-1][j-1];
                else dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < triangle[n-1].size(); i++) ans = min(ans, dp[n-1][i]);
        return ans;
    }
};