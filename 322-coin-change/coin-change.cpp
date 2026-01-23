class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for (auto& x : coins){
            for (int j = x; j <= amount; j++){
                if (dp[j-x] != INT_MAX){
                    dp[j] = min(dp[j], dp[j-x]+1);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};