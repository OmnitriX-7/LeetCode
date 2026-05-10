class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (abs(nums[j]-nums[i]) <= target && dp[j] != -1) {
                    int pick = dp[j] + 1;
                    if (pick > dp[i]) dp[i] = pick;
                }
            }
        }

        return dp[n-1];
    }
};