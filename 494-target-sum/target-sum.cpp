class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total < abs(target) || (total+target)%2 != 0) return 0;
        int s1 = (total + target)/2;
        vector<int> dp(s1+1,0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = s1; j >= nums[i]; j--) {
                dp[j] += dp[j-nums[i]];
            }
        }

        return dp[s1];
    }
};